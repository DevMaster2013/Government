#pragma once

#include <string>

namespace gov
{
	///
	/// The basic implementation for the game object
	///
	class BaseGameObject
	{
	private:
		std::string _name;	/// The name of the game object
		std::string _id;	/// The ID of the game object

	public:
		///
		/// The default constructor
		///
		BaseGameObject();

		///
		/// The initialization constructor
		///
		BaseGameObject(const std::string& name, const std::string& id);

		///
		/// The destructor of the game object
		///
		virtual ~BaseGameObject();

	public:
		///
		/// Return the name of the game object
		///
		virtual const std::string& getName() const;

		///
		/// Set the name of the game object to a new name
		///
		virtual void setName(const std::string& objectName);

		///
		/// Return the ID of the game object
		///
		virtual const std::string& getID() const;

		///
		/// Set the ID of the game object to a new ID
		///
		virtual void setID(const std::string& objectID);

		///
		/// Initilize the game object
		///
		virtual bool initialize();

		///
		/// Finalize the game object
		///
		virtual void finalize();

		///
		/// Update the game object
		///
		virtual void update();
	};
}

