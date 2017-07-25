/**
 * Copyright (C) 2016 Deepin Technology Co., Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 **/

#ifndef DSINGLETON_H
#define DSINGLETON_H

#include "dtkcore_global.h"

DCORE_BEGIN_NAMESPACE

/*!
 * a simple singleton template for std c++ 11 or later.
 *
 * example:
 *
 *  class ExampleSingleton : public QObject, public Dtk::DSingleton<ExampleSingleton>
 *  {
 *      Q_OBJECT
 *      friend class DSingleton<ExampleSingleton>;
 *  };
 *
 * Warning: for Qt, "public DSingleton<LyricService>" must be after QObject.
 */

template <class T>
class DSingleton
{
public:
    static inline T *instance()
    {
        static T  *_instance = new T;
        return _instance;
    }

protected:
    DSingleton(void) {}
    ~DSingleton(void) {}
    DSingleton(const DSingleton &) {}
    DSingleton &operator= (const DSingleton &) {}
};

DCORE_END_NAMESPACE

#endif // DSINGLETON_H
