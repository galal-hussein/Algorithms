def CookieClickerAlpha(filename):
                  fob = open(filename,'r')
                  out = open('/home/hussein/Programming/a.out','w')
                  for tc in xrange(1,int(fob.next().rstrip('\r\n'))+1):
                           line = fob.next().rstrip('\r\n').split()
                           C = round(float(line[0]),7)
                           F = round(float(line[1]),7)
                           X = round(float(line[2]),7)
                           #print C,F,X
                           T=float(0)
                           total=float(0);
                           r=float(2)
                           min= X/r
                           while total<=min:
                              T=T+(C/r)
                              r=r+F
                              total=T+(X/r)
                              if total <=min:
                                       min=total
                           out.write('Case #%d: %f8\n' % (tc,min))
                  fob.close()
                  out.close()
