#include "factory_material.h"

#include <string.h>

FactoryMater* FactoryMater::Find(const char* id) noexcept {
	FactoryMater* ptr = s_head;
	while (ptr) {
		if (!strcmp(ptr->m_id, id))
			break;
		ptr = ptr->m_next;
	}
	return ptr;
}