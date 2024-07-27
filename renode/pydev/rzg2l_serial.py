print("SCI entering")
# Set the SCR.TIE, RIE, TE, RE, and TEIE bits to 0
if request.isInit:
    print("SCI testing")
    lastVal = 0
elif request.isRead:
    request.value = lastVal
elif request.offset == 0x00:
    print("SCI 0x00")
elif request.offset == 0x01:
    print("SCI 0x01")
elif request.value == 0x41:
    print("Yes!!")
else :
    print("No!!")
# elif request.isWrite:
#     print("SCI is writing")
#     lastVal = 0x2334


self.NoisyLog("%s on REPEATER at 0x%x, value 0x%x" % (str(request.type), request.offset, request.value))