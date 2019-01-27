#include <notes.h>

DruidNotes::DruidNotes() { setupUi(this); }

QString DruidNotes::text() const { return _notes->document()->toPlainText(); }
