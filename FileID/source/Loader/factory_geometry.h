#pragma once

#include <iosfwd>
#include <memory>
#include <string>

struct IGeometry {
	virtual bool load(std::istream& in) = 0;
	virtual bool save(const std::string& path_file) const = 0;
	virtual const char* get_json() const = 0;
	virtual ~IGeometry() = default;
	static inline const char* extension = ".geom";
};

class FactoryGeom {
public:
	FactoryGeom(const char* id) noexcept : m_id(id), m_next(s_head) { s_head = this; }
	static FactoryGeom* Find(const char* id) noexcept;
	virtual std::unique_ptr<IGeometry> create() = 0;
private:
	const char* m_id;
	FactoryGeom* m_next;
	inline static FactoryGeom* s_head = nullptr;
};