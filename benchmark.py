
size = 20000

def genT():
   v = 9876
   for e in xrange( size ):
      yield v
      v = (v * 12345) % 59557





print sorted( genT() )[0]
