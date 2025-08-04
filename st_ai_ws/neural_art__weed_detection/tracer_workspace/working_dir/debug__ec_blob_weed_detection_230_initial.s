;; Start Blob '_ec_blob_weed_detection_230'
;; Start Epoch 230
label 0xe6
writefield 0 4 [0] 0x1
write 5 0 0x880100
write 5 2 0x34200000
write 5 3 0x19000
write 5 6 0x32000
write 5 8 0x0
write 5 7 0x1
write 5 12 0x6
write 5 12 0x7
write 5 14 0x3423203f
write 5 13 0x4
write 5 9 0x24
write 5 5 0x0
write 5 18 0x0
write 5 10 0x100000
write 5 17 0x0
writefield 0 4 [6] 0x1
write 11 0 0x880008
write 11 2 0x34232000
write 11 3 0x140014
write 11 4 0x8000100
write 11 6 0x200
write 11 8 0xc8000
write 11 7 0x4
write 11 12 0x6
write 11 12 0x7
write 11 14 0x342fa03f
write 11 13 0x4
write 11 9 0x24
write 11 5 0xa000
write 11 18 0x0
write 11 10 0x100000
write 11 17 0x0
write 4 0 0x2
poll 4 0 [1] 0x0 100
write 4 0 0x40000000
poll 4 0 [30] 0x0 100
write 4 0 0x1
write 4 8 0x1
writefield 11 0 [0] 0x1
writefield 5 0 [0] 0x1
poll 11 0 [31] 0x0 100
write 4 8 0x0
write 11 0 0x2
poll 11 0 [1] 0x0 100
write 11 0 0x40000000
poll 11 0 [30] 0x0 100
writefield 0 4 [6] 0x0
write 5 0 0x2
poll 5 0 [1] 0x0 100
write 5 0 0x40000000
poll 5 0 [30] 0x0 100
writefield 0 4 [0] 0x0
;; End Epoch 230
irq 0x0
;; End Blob '_ec_blob_weed_detection_230'
