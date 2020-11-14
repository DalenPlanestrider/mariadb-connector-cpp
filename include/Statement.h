/************************************************************************************
   Copyright (C) 2020 MariaDB Corporation AB

   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Library General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Library General Public License for more details.

   You should have received a copy of the GNU Library General Public
   License along with this library; if not see <http://www.gnu.org/licenses>
   or write to the Free Software Foundation, Inc.,
   51 Franklin St., Fifth Floor, Boston, MA 02110, USA
*************************************************************************************/


#ifndef _STATEMENT_H_
#define _STATEMENT_H_

#include "SQLString.h"
#include "ResultSet.h"
#include "Warning.h"
#include "Connection.h"

namespace sql
{

class MARIADB_EXPORTED Statement {
  Statement(const Statement &);
  void operator=(Statement &);
public:
  enum {
    CLOSE_CURRENT_RESULT= 1,
    KEEP_CURRENT_RESULT,
    CLOSE_ALL_RESULTS
  };
  enum {
    EXECUTE_FAILED= -3,
    SUCCESS_NO_INFO= -2
  };
  enum {
    RETURN_GENERATED_KEYS= 1,
    NO_GENERATED_KEYS
  };
  Statement() {}
  virtual ~Statement(){}

  virtual bool execute(const SQLString& sql)=0;
  virtual bool execute(const SQLString& sql, int32_t autoGeneratedKeys)=0;
  virtual bool execute(const SQLString& sql, int32_t* columnIndexes)=0;
  virtual bool execute(const SQLString& sql,const SQLString* columnNames)=0;

  virtual ResultSet* executeQuery(const SQLString& sql)=0;

  virtual int32_t executeUpdate(const SQLString& sql)=0;
  virtual int32_t executeUpdate(const SQLString& sql, int32_t autoGeneratedKeys)=0;
  virtual int32_t executeUpdate(const SQLString& sql, int32_t* columnIndexes)=0;
  virtual int32_t executeUpdate(const SQLString& sql,const SQLString* columnNames)=0;

  virtual int64_t executeLargeUpdate(const SQLString& sql)=0;
  virtual int64_t executeLargeUpdate(const SQLString& sql, int32_t autoGeneratedKeys)=0;
  virtual int64_t executeLargeUpdate(const SQLString& sql, int32_t* columnIndexes)=0;
  virtual int64_t executeLargeUpdate(const SQLString& sql, const SQLString* columnNames)=0;

  virtual void close()=0;
  virtual uint32_t getMaxFieldSize()=0;
  virtual void setMaxFieldSize(uint32_t max)=0;
  virtual int32_t getMaxRows()=0;
  virtual void setMaxRows(int32_t max)=0;
  virtual int64_t getLargeMaxRows()=0;
  virtual void setLargeMaxRows(int64_t max)=0;
  virtual void setEscapeProcessing(bool enable)=0;
  virtual int32_t getQueryTimeout()=0;
  virtual void setQueryTimeout(int32_t seconds)=0;
  virtual void cancel()=0;
  virtual SQLWarning* getWarnings()=0;
  virtual void clearWarnings()=0;
  virtual void setCursorName(const SQLString& name)=0;
  virtual Connection* getConnection()=0;
  virtual ResultSet* getGeneratedKeys()=0;
  virtual int32_t getResultSetHoldability()=0;
  virtual bool isClosed()=0;
  virtual bool isPoolable()=0;
  virtual void setPoolable(bool poolable)=0;
  virtual ResultSet* getResultSet()=0;
  virtual int32_t getUpdateCount()=0;
  virtual int64_t getLargeUpdateCount()=0;
  virtual bool getMoreResults()=0;
  virtual bool getMoreResults(int32_t current)=0;
  virtual int32_t getFetchDirection()=0;
  virtual void setFetchDirection(int32_t direction)=0;
  virtual int32_t getFetchSize()=0;
  virtual void setFetchSize(int32_t rows)=0;
  virtual int32_t getResultSetConcurrency()=0;
  virtual int32_t getResultSetType()=0;
  virtual void addBatch(const SQLString& sql)=0;
  virtual void clearBatch()=0;
  virtual sql::Ints* executeBatch()=0;
  virtual sql::Longs* executeLargeBatch()=0;
  virtual void closeOnCompletion()=0;
  virtual bool isCloseOnCompletion()=0;
  virtual Statement* setResultSetType(int32_t rsType)=0;
};

}
#endif
