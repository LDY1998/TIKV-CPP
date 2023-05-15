#pragma once


namespace KV {
enum TypeID {
  INVALID = 0,
  BOOLEAN,
  TINYINT,
  SMALLINT,
  INTEGER,
  BIGINT,
  DECIMAL,
  TIMESTAMP,
  DATE,
  VARCHAR,
  VARBINARY,
  ARRAY,
  UDT,
  MAX_VALUE
};
}