/*
 * Copyright 2004 Sandia Corporation.
 * Under the terms of Contract DE-AC04-94AL85000, there is a non-exclusive
 * license for use of this work by or on behalf of the
 * U.S. Government. Redistribution and use in source and binary forms, with
 * or without modification, are permitted provided that this Notice and any
 * statement of authorship are reproduced on all copies.
 */

#ifndef _pqEventTranslator_h
#define _pqEventTranslator_h

#include <QObject>
#include <QVector>

class pqWidgetEventTranslator;

/// Manages translation of low-level Qt events to high-level ParaQ events that can be serialized as test-cases, demos, tutorials, etc.
class pqEventTranslator :
  public QObject
{
  Q_OBJECT

public:
  pqEventTranslator();
  ~pqEventTranslator();

  /// Adds a new translator to the current working set of widget translators.  pqEventTranslator assumes control of the lifetime of the supplied object.
  void addWidgetEventTranslator(pqWidgetEventTranslator*);

signals:
  /// This signal will be emitted every time a translator generates a high-level ParaQ event.  Observers should connect to this signal to serialize high-level events.
  void abstractEvent(const QString& Widget, const QString& Command, const QString& Arguments);

private:
  pqEventTranslator(const pqEventTranslator&);
  pqEventTranslator& operator=(const pqEventTranslator&);

  bool eventFilter(QObject* Object, QEvent* Event);

  /// Stores the working set of widget translators  
  QVector<pqWidgetEventTranslator*> translators;
};

#endif // !_pqEventTranslator_h

