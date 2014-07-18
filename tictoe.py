#Google CodeJam Qualification round 2013 
def tictoe(filename):
         fob = open(filename,'r')
         out = open('/home/hussein/Programming/a.out','w')
         for tc in xrange(1,int(fob.next().rstrip('\r\n'))+1):
                  X = False
                  O = False
                  I = False
                  Game=[]
                  row = ''
                  for i in range(4):
                           row = fob.next().rstrip('\r\n')
                           if(row==''):
                                    row=fob.next().rstrip('\r\n')
                           Game.append(row)
                  for i in Game:
                           if('.' in i):
                                    I=True

                  #for each row
                  for i in Game:
                           if(i.count('X')==4 or (i.count('X') ==3 and i.count('T')==1)):
                                    X=True
                           elif(i.count('O')==4 or (i.count('O') ==3 and i.count('T')==1)):
                                    O=True
                  #for each col
                  col =[]
                  s=''
                  for i in range(4):
                           for j in range(4):
                                    s+=Game[j][i]
                           col.append(s)
                           s=''
                  for i in col:
                           if(i.count('X')==4 or (i.count('X') ==3 and i.count('T')==1)):
                                    X=True
                           elif(i.count('O')==4 or (i.count('O') ==3 and i.count('T')==1)):
                                    O=True
                  #for left diagonal
                  i = Game[0][0]+Game[1][1]+Game[2][2]+Game[3][3]
                  if(i.count('X')==4 or (i.count('X') ==3 and i.count('T')==1)):
                                    X=True
                  elif(i.count('O')==4 or (i.count('O') ==3 and i.count('T')==1)):
                                    O=True

                  #for right diagonal
                  i = Game[0][3]+Game[1][2]+Game[2][1]+Game[3][0]
                  if(i.count('X')==4 or (i.count('X') ==3 and i.count('T')==1)):
                                    X=True
                  elif(i.count('O')==4 or (i.count('O') ==3 and i.count('T')==1)):
                                    O=True

                  if(I==False and X==False and O==False):
                           out.write('Case #%d: Draw\n'%(tc))
                  elif(X==True):
                           out.write('Case #%d: X won\n'%(tc))
                  elif(O==True):
                           out.write('Case #%d: O won\n'%(tc))
                  elif(I==True and X==False and O==False):
                           out.write('Case #%d: Game has not completed\n'%(tc))
                           
                           
         fob.close()
         out.close()
                           
                           
