CC=gcc
CFLAGS=-c -std=c99
DIRS=-Igraph -Icontroller -Iview
SOURCES=main.c graph/Graph.c graph/Queue.c controller/GraphController.c view/Dialog.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=main

all: $(SOURCES)  $(EXECUTABLE)

.c.o:
	@($(CC) $(DIRS) $(CFLAGS) $< -o $@)
	@echo "- ${<}"

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -lm -o $@
	@echo "=== complete ==="

clean:
	find -not \( -wholename '*/cmake-build-debug/*' \) -name '*.o' -delete
