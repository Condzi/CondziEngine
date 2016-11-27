#include "Demo/EntityFactory.hpp"

void demo::EntityFactory::SetResourceCachePointer(ce::ResourceCache * resourceCache)
{
	//CE_ASSERT(resourceCache, "cannot be nullptr");
	
	internal::ResourceCachePtr = resourceCache;
}
