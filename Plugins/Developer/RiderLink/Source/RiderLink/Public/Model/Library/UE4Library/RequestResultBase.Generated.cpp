//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a RdGen v1.11.
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------
#include "RequestResultBase.Generated.h"


#include "RequestResultBase_Unknown.Generated.h"

#ifdef _MSC_VER
#pragma warning( push )
#pragma warning( disable:4250 )
#pragma warning( disable:4307 )
#pragma warning( disable:4267 )
#pragma warning( disable:4244 )
#pragma warning( disable:4100 )
#endif

namespace JetBrains {
namespace EditorPlugin {
// companion
// constants
// initializer
void RequestResultBase::initialize()
{
}
// primary ctor
RequestResultBase::RequestResultBase(int32_t requestID_) :
rd::IPolymorphicSerializable()
,requestID_(std::move(requestID_))
{
    initialize();
}
// secondary constructor
// default ctors and dtors
// reader
rd::Wrapper<RequestResultBase> RequestResultBase::readUnknownInstance(rd::SerializationCtx& ctx, rd::Buffer & buffer, rd::RdId const& unknownId, int32_t size)
{
    int32_t objectStartPosition = buffer.get_position();
    auto requestID_ = buffer.read_integral<int32_t>();
    auto unknownBytes = rd::Buffer::ByteArray(objectStartPosition + size - buffer.get_position());
    buffer.read_byte_array_raw(unknownBytes);
    RequestResultBase_Unknown res{std::move(requestID_), unknownId, unknownBytes};
    return rd::Wrapper<RequestResultBase_Unknown>(std::move(res));
}
// writer
// virtual init
// identify
// getters
int32_t const & RequestResultBase::get_requestID() const
{
    return requestID_;
}
// intern
// equals trait
// equality operators
bool operator==(const RequestResultBase &lhs, const RequestResultBase &rhs) {
    if (lhs.type_name() != rhs.type_name()) return false;
    return lhs.equals(rhs);
}
bool operator!=(const RequestResultBase &lhs, const RequestResultBase &rhs){
    return !(lhs == rhs);
}
// hash code trait
size_t RequestResultBase::hashCode() const noexcept
{
    size_t __r = 0;
    __r = __r * 31 + (rd::hash<int32_t>()(get_requestID()));
    return __r;
}
// type name trait
std::string RequestResultBase::type_name() const
{
    return "RequestResultBase";
}
// static type name trait
std::string RequestResultBase::static_type_name()
{
    return "RequestResultBase";
}
// polymorphic to string
std::string RequestResultBase::toString() const
{
    std::string res = "RequestResultBase\n";
    res += "\trequestID = ";
    res += rd::to_string(requestID_);
    res += '\n';
    return res;
}
// external to string
std::string to_string(const RequestResultBase & value)
{
    return value.toString();
}
}
}

#ifdef _MSC_VER
#pragma warning( pop )
#endif

