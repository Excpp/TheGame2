#pragma once
#include <memory>
#include "stdInclude.h"
#include "TuplePlus.h"
#include "Settings.h"


template<class T>
using StdUPtr_t = std::unique_ptr<T>; // pointer used to store module

template<class T>
using MDep_t = const StdUPtr_t<T> &; // module dependency type

template<class ...MTypes>
using MDepPack_t = TypesPack_t<MDep_t<MTypes>...>;


template<class ...DTypes> // DTypes = Dependencies (other modules)
class Module
{
public:

	// for inherting classes
	using ModuleBase_t = Module<DTypes...>;


	using UsedMDepPack_t = MDepPack_t<DTypes...>;

public:

	template<class ...MTypes>
	Module(const MDepPack_t<MTypes...> & dependencies) : dependencies(typename MDepPack_t<DTypes...>::Base_t(dependencies.get<MDep_t<DTypes>>()...)) {}

	virtual ~Module() = default;


	virtual void startUp() {};

	virtual void update(float_t dt) {};

	virtual void shutdown() 
	{
#ifdef _DEBUG
		std::cout << std::type_index(typeid(*this)).name() << std::endl;
#endif // _DEBUG
	};


protected:

	template<class T>
	T& getDependency() const
	{
		return *dependencies.get<MDep_t<T> >();
	}


protected:

	const UsedMDepPack_t dependencies;

};