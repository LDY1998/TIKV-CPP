

namespace api
{
    template <typename KeyType, typename ValueType>
    class DataAccessInterface
    {
        virtual ValueType Get(const KeyType& key) = 0;
        virtual void Put(const KeyType& key, const ValueType& value) = 0;
    };
} // namespace api
