#pragma once
#include "Engine/Logger/Logger.hpp"
#include <map>
#include <typeinfo>
#include <memory>

namespace ce
{
	template< typename Resource >
	class NewResourceCache
	{
	public:
		NewResourceCache();

		Resource* GetResource(const std::string & name);
		Resource* AddResource(Resource* r, const std::string & name);
		void DeleteResource(const std::string & name);
		void DeleteAll();

	private:
		std::map< std::string, std::shared_ptr<Resource> > m_resources;
	};
}