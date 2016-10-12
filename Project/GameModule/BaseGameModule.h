#pragma once

#include "BaseGameObject.h"

#include <string>
#include <map>

namespace gov
{
	class BaseGameModule : public  BaseGameObject
	{
	private:
		std::map<std::string, BaseGameModule*> _subModules;	/// The collection of sub modules in the module

	public:
		///
		/// The Default constructor
		///
		BaseGameModule();

		///
		/// The initialization constructor
		///
		BaseGameModule(const std::string& name, const std::string& id);

		///
		/// The destructor of the game module
		///
		virtual ~BaseGameModule();

	public:
		///
		/// Add a submodule to the module
		///
		virtual void addSubModule(BaseGameModule* subModule) = 0;

		///
		/// Remove a submodule from this module
		///
		virtual void removeSubModule(const std::string& moduleID) = 0;

		///
		/// Return the submodule that belongs to the specified ID
		///
		virtual BaseGameModule* getSubModule(const std::string& moduleID) = 0;

	public:
		///
		/// Inherited via BaseGameObject
		///
		virtual bool	initialize()					override;
		virtual void	finalize()						override;
		virtual void	update(double elapsedTime)		override;
	};
}

