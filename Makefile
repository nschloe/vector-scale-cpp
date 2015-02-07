
TARGET=vector-scaling-timer

default:
	g++ -c -O3 $(TARGET).cpp
	g++ $(TARGET).o -lcblas

clean:
	@rm -f \
	  $(TARGET).o \
	  a.out
