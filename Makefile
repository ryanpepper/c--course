CPPFLAGS += -MD -MP -std=c++11

SOURCES := $(wildcard *.cc)

bounce: $(SOURCES:%.cc=%.o)
	$(CXX) -o $@ $^ $(LDFLAGS)

clean:
	rm *.o *.d executable

-include $(SOURCES:%.cc=%.d)
