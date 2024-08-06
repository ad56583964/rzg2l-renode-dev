# print("SCI entering")
# Set the SCR.TIE, RIE, TE, RE, and TEIE bits to 0
if request.isInit:
    print("SCI testing")
# elif request.isRead:
#     request.value = lastVal
elif request.isWrite:
    if request.offset == 0x00:
        print("SCI is writing 0x00")
        # callables = [attr for attr in dir(self) if callable(getattr(self, attr))]
        # getvalue = 0
        getvalue = self.ReadQuadWord(0x00)
        print(f"Type of getvalue: {type(getvalue)}")
        # print(callables)
        print("0x00 put {}",format(request.value))
    elif request.offset == 0x01:
        print("SCI 0x01")
# elif request.isRead:
#     print("SCI is reading")