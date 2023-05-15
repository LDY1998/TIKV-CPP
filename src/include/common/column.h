#include <string>
#include "type/type.h"

#pragma once

namespace KV {
class Column {
 public:
  /**
   * Non-variable-length constructor for creating a Column.
   * @param column_name name of the column
   * @param type type of the column
   */
  Column(std::string column_name, TypeID type) : column_name_(std::move(column_name)), column_type_(type) {}

  /**
   * @brief Variable-length constructor for creating a Column.
   * @param column_name name of the column
   * @param type type of the column
   * @param len length of varlen
   */
  Column(std::string column_name, TypeID type, uint32_t len)
      : column_name_(std::move(column_name)),
        column_type_(type),
        fixed_length_(TypeSize(type)),
        variable_length_(len) {}

  /**
   * @brief Copy constructor
   * @param column_name name of the column
   * @param column column to copy from
   */
  Column(std::string column_name, const Column &column)
      : column_name_(std::move(column_name)),
        column_type_(column.column_type_),
        fixed_length_(column.fixed_length_),
        variable_length_(column.variable_length_) {}
    
    /** @return column name */
    const std::string &GetColumnName() const { return column_name_; }

    /** @return column length */
    uint32_t GetLength() const {
        if (IsInlined()) {
            return fixed_length_;
        }
        return variable_length_;
     }

    /** @return true if column is inlined, false otherwise */
    bool IsInlined() const { return column_type_ != TypeID::VARCHAR; }


 private:
  /**
   * Return the size in bytes of the type.
   * @param type type whose size is to be determined
   * @return size in bytes
   */
  static auto TypeSize(TypeID type) -> uint8_t {
    switch (type) {
      case TypeID::BOOLEAN:
      case TypeID::TINYINT:
        return 1;
      case TypeID::SMALLINT:
        return 2;
      case TypeID::INTEGER:
        return 4;
      case TypeID::BIGINT:
      case TypeID::DECIMAL:
      case TypeID::TIMESTAMP:
        return 8;
      case TypeID::VARCHAR:
        // TODO(Amadou): Confirm this.
        return 12;
      default: {
        // UNREACHABLE("Cannot get size of invalid type");
      }
    }
  }
  /** Column name. */
  std::string column_name_;

  /** Column value's type. */
  TypeID column_type_;

  /** For a non-inlined column, 
   * ?this is the size of a pointer. 
   * Otherwise, the size of the fixed length column. */
  uint32_t fixed_length_;

  /** For an inlined column, 0. Otherwise, the length of the variable length column. */
  uint32_t variable_length_{0};

  /** Column offset in the tuple. */
  uint32_t column_offset_{0};
};
}  // namespace KV
