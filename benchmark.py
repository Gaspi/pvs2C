
def genT():
   v = 9876
   for e in xrange(1000):
      yield v
      v = (v * 12345) % 59557

print min( genT() )
