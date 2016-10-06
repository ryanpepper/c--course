CPPFLAGS += -MD -MP

SOURCES := $(wildcard *.cc)

executable: $(SOURCES:%.cc=%.o)
	$(CXX) -o $@ $^ $(LDFLAGS) -std=c++11

clean:
	rm *.o *.d executable

-include $(SOURCES:%.cc=%.d)
