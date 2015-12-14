#ifndef _LOGCPP_HELPERS_OBJECTPTR_HPP_
#define _LOGCPP_HELPERS_OBJECTPTR_HPP_

#include <memory>

#define OBJECT_PTR(c) \
    using Ptr = std::shared_ptr<c>;

#endif