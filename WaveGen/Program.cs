using System;
using System.Collections.Generic;

namespace WaveGen
{
    class Program
    {
        static int f_base = 8000000;
        static int f_pwm = f_base / 256;

        static int mod(int x, int m)
        {
            return (x % m + m) % m;
        }

        static void Main(string[] args)
        {

            Console.WriteLine($"Base frequency: {f_base}");
            Console.WriteLine($"PWM frequency: {f_pwm}");

            string[] toneNames = new string[] { "C", "Cs", "D", "Ds", "E", "F", "Fs", "G", "Gs", "A", "As", "H" };
            int octave = 4;
            double baseTone = 440;

            int minTone = -22;
            int maxTone = 3;

            var lines = new List<string>();

            lines.Add("#include <avr/pgmspace.h>");
            lines.Add("");
            lines.Add("#ifndef WAVES_H_");
            lines.Add("#define WAVES_H_");
            lines.Add("");

            for (int i = minTone; i <= maxTone; i++)
            {
                var index = i + 9;

                var f = Math.Pow(2, (double)i / 12) * baseTone;
                var octaveNumber = octave + (int)Math.Floor((double)index / toneNames.Length);

                var toneName = toneNames[mod(index, toneNames.Length)] + octaveNumber;

                double sampleCount = (double)f_pwm / f;
                int sampleCountInt = (int)Math.Round(sampleCount);
                var synthesisedFrequency = (double)f_pwm / sampleCountInt;
                var err = Math.Abs(f - synthesisedFrequency) / f * 100;

                Console.WriteLine($"{toneName.PadRight(8)}| {f:F2} | {synthesisedFrequency:F2} | {err:F2}% | {sampleCountInt.ToString().PadLeft(5)}");

                lines.Add($"const uint8_t sineWave_{toneName}_{f:F0}[] PROGMEM = ");
                lines.Add("{");

                for (int sample = 0; sample < sampleCountInt; sample++)
                {
                    var amplitude = Waveform((double)sample / sampleCountInt);

                    var amplitudeByte = Math.Floor((amplitude + 1.0) * 0.5 * 256);
                    amplitudeByte = Math.Min(255, amplitudeByte);
                    amplitudeByte = Math.Max(0, amplitudeByte);

                    lines.Add($"    {amplitudeByte},");
                }

                lines.Add("};");
                lines.Add("");


            }

            // Hull Curve
            lines.Add($"const uint8_t hullCurve[] = ");
            lines.Add("{");

            int attack = 10;
            int sustain = 40;

            for (int sample = 0; sample < attack; sample++)
            {
                var amplitude = Math.Sin(Math.PI * sample / (2 * attack));

                var amplitudeByte = Math.Floor(amplitude * 256);
                amplitudeByte = Math.Min(255, amplitudeByte);
                amplitudeByte = Math.Max(0, amplitudeByte);

                lines.Add($"    {amplitudeByte},");
            }

            for (int sample = attack; sample < sustain; sample++)
            {

                lines.Add($"    {255},");
            }

            for (int sample = sustain; sample < 256; sample++)
            {
                double x = (double)(sample - sustain) / (256 - sustain);
                var amplitude = Math.Pow(Math.E, -1.0 * 5 * x);

                var amplitudeByte = Math.Floor(amplitude * 256);
                amplitudeByte = Math.Min(255, amplitudeByte);
                amplitudeByte = Math.Max(0, amplitudeByte);

                lines.Add($"    {amplitudeByte},");
            }

            lines.Add("};");
            lines.Add("");
            lines.Add("#endif /* WAVES_H_ */");
            lines.Add("");
            

            var filename = "waves.h";

            System.IO.File.WriteAllLines(filename, lines);

            var filename2 = "../DisplayTest/waves.h";

            System.IO.File.WriteAllLines(filename2, lines);
        }

        // v - value between 0 and 1
        // returns -1 ... 1
        private static double Waveform(double v) 
        {
            //return Math.Sin(2 * Math.PI * v);

            // var x = 2.0 * v;
            // return Math.Pow(Math.Sin(Math.PI*x), 3) + Math.Sin(Math.PI * (x + 2.0 / 3.0));

            var a = Math.Sin(2 * Math.PI * v) + 0.5 * Math.Sin(2 * Math.PI * 2 * v) + 0.33 * Math.Sin(2 * Math.PI * 3 * v) + 0.25 * Math.Sin(2 * Math.PI * 4 * v);
            return a / (1 + 0.5 + 0.33 + 0.25);
        }
    }
}
