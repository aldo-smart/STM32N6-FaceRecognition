;; Start Blob '_ec_blob_weed_detection_1'
;; Start Epoch 1
label 0x1
writefield 0 4 [6] 0x1
write 11 0 0x880100
write 11 2 0x342e0000
write 11 3 0x8000
write 11 6 0x10000
write 11 8 0x0
write 11 7 0x0
write 11 12 0x6
write 11 12 0x7
write 11 14 0x3431003f
write 11 13 0x3
write 11 9 0x24
write 11 5 0x0
write 11 18 0x0
write 11 10 0x100000
write 11 17 0x0
writefield 0 4 [4] 0x1
write 9 0 0x880008
write 9 2 0x34310000
write 9 3 0x800080
write 9 4 0xc0002
write 9 6 0x4
write 9 8 0x30000
write 9 7 0x3
write 9 12 0x6
write 9 12 0x7
write 9 14 0x3434003f
write 9 13 0x3
write 9 9 0x24
write 9 5 0x600
write 9 18 0x0
write 9 10 0x100000
write 9 17 0x0
write 4 0 0x2
poll 4 0 [1] 0x0 100
write 4 0 0x40000000
poll 4 0 [30] 0x0 100
write 4 0 0x1
write 4 6 0xd
writefield 9 0 [0] 0x1
writefield 11 0 [0] 0x1
poll 9 0 [31] 0x0 100
write 4 6 0x0
write 9 0 0x2
poll 9 0 [1] 0x0 100
write 9 0 0x40000000
poll 9 0 [30] 0x0 100
writefield 0 4 [4] 0x0
write 11 0 0x2
poll 11 0 [1] 0x0 100
write 11 0 0x40000000
poll 11 0 [30] 0x0 100
writefield 0 4 [6] 0x0
;; End Epoch 1
irq 0x0
;; End Blob '_ec_blob_weed_detection_1'
