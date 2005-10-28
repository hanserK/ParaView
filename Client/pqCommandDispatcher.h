/*
 * Copyright 2004 Sandia Corporation.
 * Under the terms of Contract DE-AC04-94AL85000, there is a non-exclusive
 * license for use of this work by or on behalf of the
 * U.S. Government. Redistribution and use in source and binary forms, with
 * or without modification, are permitted provided that this Notice and any
 * statement of authorship are reproduced on all copies.
 */

#ifndef _pqCommandDispatcher_h
#define _pqCommandDispatcher_h

#include <QObject>

class pqCommand;

/// Abstract interface for an object that implements an "update" policy
/** \todo Need to figure-out how this will interoperate with pqSMAdaptor and server-manager undo/redo */
class pqCommandDispatcher :
  public QObject
{
  Q_OBJECT
  
public:
  virtual void dispatchCommand(pqCommand*) = 0;

signals:
  void updateWindow();
};

#endif // !pqCommandDispatcher_h

