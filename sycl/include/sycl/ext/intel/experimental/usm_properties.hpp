#pragma once

#include <CL/sycl/context.hpp>
#include <CL/sycl/detail/property_helper.hpp>
#include <CL/sycl/properties/property_traits.hpp>

__SYCL_INLINE_NAMESPACE(cl) {
namespace sycl {
namespace ext {

namespace oneapi {
namespace property {
namespace usm {
class device_read_only
    : public sycl::detail::DataLessProperty<sycl::detail::DeviceReadOnly> {
public:
  device_read_only() = default;
};
} // namespace usm
} // namespace property
} // namespace oneapi

namespace intel {
namespace experimental {
namespace property {
namespace usm {

class buffer_location
    : public sycl::detail::PropertyWithData<
          sycl::detail::PropWithDataKind::AccPropBufferLocation> {
public:
  buffer_location(uint64_t Location) : MLocation(Location) {}
  uint64_t get_buffer_location() const { return MLocation; }

private:
  uint64_t MLocation;
};

} // namespace usm
} // namespace property
} // namespace experimental
} // namespace intel
} // namespace ext

template <>
struct is_property<ext::oneapi::property::usm::device_read_only>
    : std::true_type {};

template <>
struct is_property<ext::intel::experimental::property::usm::buffer_location>
    : std::true_type {};

} // namespace sycl
} // __SYCL_INLINE_NAMESPACE(cl)
