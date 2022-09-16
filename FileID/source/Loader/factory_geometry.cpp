#include "factory_geometry.h"

#include <string.h>

FactoryGeom* FactoryGeom::Find(const char* id) noexcept {
	FactoryGeom* ptr = s_head;
	while (ptr) {
		if (!strcmp(ptr->m_id, id))
			break;
		ptr = ptr->m_next;
	}
	return ptr;
}