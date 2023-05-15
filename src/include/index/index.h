

//===----------------------------------------------------------------------===//
//
//                         KV
//
// index.h
//
// Identification: src/include/storage/index/index.h
//
// Copyright (c) 2015-2019, Carnegie Mellon University Database Group
//
//===----------------------------------------------------------------------===//

namespace KV
{
    /**
     * class Index - Base class for derived indices of different types
     *
     * The index structure majorly maintains information on the schema of the
     * underlying table and the mapping relation between index key
     * and tuple key, and provides an abstracted way for the external world to
     * interact with the underlying index implementation without exposing
     * the actual implementation's interface.
     *
     * Index object also handles predicate scan, in addition to simple insert,
     * delete, predicate insert, point query, and full index scan. Predicate scan
     * only supports conjunction, and may or may not be optimized depending on
     * the type of expressions inside the predicate.
     */

    class Index
    {
    };
}
