#pragma once

#include <fstream>
#include <string>

namespace gov
{
	///
	/// The basic archive class that responsible for saving and loading the game objects
	/// in the game
	///
	class BaseGameArchive
	{
	private:
		std::fstream _archiveStream;	/// The stream used in archive
		bool _forReading;				/// Is this archive is used for reading

	public:
		///
		/// The default constructor
		///
		BaseGameArchive();

		///
		/// The initialization constructor
		///
		BaseGameArchive(const std::string& fileName, bool isRead);

		///
		/// The destructor of the game arvhive
		///
		virtual ~BaseGameArchive();

	public:
		///
		/// Open the file arvhice
		/// isRead : if open the file for reading or writing
		///
		virtual bool open(const std::string& fileName, bool isRead);

		///
		/// Close the archive
		///
		virtual void close();
	};
}
