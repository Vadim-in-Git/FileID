//#include <iostream>
#include "loader.h"
#include "geometry_frame.h"
#include "geometry_mesh.h"
#include "material_backofen.h"

#include <iostream>

void create_files() {
	GeomFrame geom_frame;
	geom_frame.set_data("Some FRAME data is here!");
	std::cout << geom_frame.save("file_frame.geom") << '\n';
	GeomMesh geom_mesh;
	geom_mesh.set_data("Some MESH data is here!");
	std::cout << geom_mesh.save("file_mesh.geom") << '\n';
	MaterBackofen mater_backofen;
	mater_backofen.set_data("Some BACKOFEN data is here!");
	std::cout << mater_backofen.save("file_backofen.prop") << '\n';
}

void load_data() {
	auto ptr1 = load_geometry("file_frame.geom");
	std::cout << ptr1->get_json() << '\n';
	auto ptr2 = load_geometry("file_mesh.geom");
	std::cout << ptr2->get_json() << '\n';
	auto ptr3 = load_material("file_backofen.prop");
	std::cout << ptr3->get_json() << '\n';
	
	auto data = load("file_mesh.geom");
	switch (data.index()) {
	case 0: 				std::cout << "No value!"; break;
	case 1: 				std::cout << std::get<1>(data)->get_json() << '\n'; break;
	case 2: 				std::cout << std::get<2>(data)->get_json() << '\n'; break;
	case std::variant_npos: std::cout << "Valueless by exception!"; break;
	default: 				std::cout << "Can’t happen!";
	}
}

int main() {
	std::cout << std::boolalpha;
	create_files();
	load_data();
	
	return 0;
}