add_library(kv_type OBJECT type.cpp)

set(ALL_OBJECT_FILES
    ${ALL_OBJECT_FILES} $<TARGET_OBJECTS:kv_type>
    PARENT_SCOPE)