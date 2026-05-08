CXX = g++
CXXFLAGS = -std=c++2b -Wall -g -pthread
LDFLAGS = -pthread

TARGET = main
SRCS = main.cpp ListsDemo.cpp#vector.cpp
OBJS = $(SRCS:.cpp=.o)

# Primera regla (por defecto)
all: $(TARGET)

# Enlace del ejecutable
$(TARGET): $(OBJS)
	$(CXX) $(LDFLAGS) $(OBJS) -o $(TARGET)

# Compilación de archivos objeto
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpieza
clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean