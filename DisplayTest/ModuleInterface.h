/*
 * ModuleInterface.h
 *
 * Created: 10/08/2020 22:25:50
 *  Author: Jan.Reinhardt
 */ 


#ifndef MODULEINTERFACE_H_
#define MODULEINTERFACE_H_

class IModule {
	public:
	virtual void load() = 0;
	virtual void update() = 0;
	virtual void unload() = 0;
};


#endif /* MODULEINTERFACE_H_ */