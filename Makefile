CXXFLAGS =	-O2 -g -Wall -fmessage-length=0

OBJS =		Test_1.o

LIBS =

TARGET =	target

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
