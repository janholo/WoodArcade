using System;
using System.Collections.Generic;

namespace WaveGen
{
    class Program
    {
        static int f_base = 8000000;
        static int f_pwm = f_base / 256;

        static int mod(int x, int m) {
            return (x%m + m)%m;
        }

        static void Main(string[] args)
        {
            
            Console.WriteLine($"Base frequency: {f_base}");
            Console.WriteLine($"PWM frequency: {f_pwm}");

            string[] toneNames = new string[] {"C", "Cs", "D", "Ds", "E", "F", "Fs", "G", "Gs", "A", "As", "H"};
            int octave = 4;
            double baseTone = 440;

            int minTone = -9;
            int maxTone = 14;

            var lines = new List<string>();

            for(int i = minTone; i < maxTone; i++)
            {
                var index = i + 9;

                var f = Math.Pow(2, (double)i/12) * baseTone;
                var octaveNumber = octave + (index / toneNames.Length);

                var toneName = toneNames[mod(index,toneNames.Length)] + octaveNumber;

                double sampleCount = (double)f_pwm / f;
                int sampleCountInt = (int)Math.Round(sampleCount);
                var synthesisedFrequency = (double)f_pwm / sampleCountInt;
                var err = Math.Abs(f - synthesisedFrequency)/f * 100;

                Console.WriteLine($"{toneName.PadRight(8)}| {f:F2} | {synthesisedFrequency:F2} | {err:F2}% | {sampleCountInt.ToString().PadLeft(5)}");

                lines.Add($"uint8_t sineWave_{toneName}_{f:F0}[] = ");
                lines.Add("{");

                for(int sample = 0; sample < sampleCountInt; sample++)
                {
                    var amplitude = Math.Sin(2*Math.PI*sample/sampleCountInt);

                    var amplitudeByte = Math.Floor((amplitude+1.0)*0.5*256);
                    amplitudeByte = Math.Min(255, amplitudeByte);
                    amplitudeByte = Math.Max(0, amplitudeByte);

                    lines.Add($"    {amplitudeByte},");
                }

                lines.Add("};");
                lines.Add("");

                
            }

            // Hull Curve
            lines.Add($"uint8_t hullCurve[] = ");
            lines.Add("{");

            for(int sample = 0; sample < 256; sample++)
            {
                var amplitude = Math.Sin(Math.PI*sample/256);

                var amplitudeByte = Math.Floor(amplitude*256);
                amplitudeByte = Math.Min(255, amplitudeByte);
                amplitudeByte = Math.Max(0, amplitudeByte);

                lines.Add($"    {amplitudeByte},");
            }

            lines.Add("};");
            lines.Add("");


            var filename = "waves.h";

            System.IO.File.WriteAllLines(filename, lines);

            var filename2 = "../DisplayTest/waves.h";

            System.IO.File.WriteAllLines(filename2, lines);
        }
    }
}
