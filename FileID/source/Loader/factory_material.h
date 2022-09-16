#pragma once

#include <iosfwd>
#include <memory>
#include <string>

struct IMaterial {
	virtual bool load(std::istream& in) = 0;
	virtual bool save(const std::string& path_file) const = 0;
	virtual const char* get_json() const = 0;
	virtual ~IMaterial() = default;
	static inline const char* extension = ".prop";
};

class FactoryMater {
public:
	FactoryMater(const char* id) noexcept : m_id(id), m_next(s_head) { s_head = this; }
	static FactoryMater* Find(const char* id) noexcept;
	virtual std::unique_ptr<IMaterial> create() = 0;
private:
	const char* m_id;
	FactoryMater* m_next;
	inline static FactoryMater* s_head = nullptr;
};