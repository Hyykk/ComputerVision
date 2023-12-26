# 🖼️ ComputerVision Study
Detailed codes are in mainframe.cpp in the Project and Practice branches.
## RGB to HSI
![RGBtoHSI](https://github.com/Hyykk/ComputerVision/assets/114062987/3792773b-0d62-4593-9c1d-929ebd34781d)

H = Hue
S = 1 - 3/(R+G+B) * min(R,G,B) (if R+G+B=0, S=0)
I = (R+G+B) / 3

## RGB to NRG
![RGBtoNRG](https://github.com/Hyykk/ComputerVision/assets/114062987/b18606e1-fa3d-4159-823c-99dcd0039779)

R or G or B / (R+G+B)

## Luminance Contrast
![constrast](https://github.com/Hyykk/ComputerVision/assets/114062987/edd9448a-d4be-4eee-81c0-87646f48ec90)![contrast1](https://github.com/Hyykk/ComputerVision/assets/114062987/50718b55-d102-43ed-ac68-b77ecb143057)

Xout = (b'-a')/(b-a) * (Xin - a) + a'
Xin = (Xin < a?a|(Xin > b?b|Xin))

## Morphology (Dilation, Erosion, Opening, Closing, Boundary Extraction
![morphology](https://github.com/Hyykk/ComputerVision/assets/114062987/420b8888-6d0c-4ccf-a103-c86851da5e57)


## Labeling
![labeling](https://github.com/Hyykk/ComputerVision/assets/114062987/87a623e7-d583-40f5-bc74-c9fe15a5a267)

## Histogram Equalization, Histogram Matching
![histogram1](https://github.com/Hyykk/ComputerVision/assets/114062987/dbf7176d-7bcf-4c1e-854a-62554666a056)
![histogram2](https://github.com/Hyykk/ComputerVision/assets/114062987/447d50ab-2050-4e05-b1c4-2b67746dd031)
![histogram3](https://github.com/Hyykk/ComputerVision/assets/114062987/42ff2e7f-6894-437b-92b2-c019cd040794)


## Hough Transform (Circle Hough Localization)
![HoughTransform](https://github.com/Hyykk/ComputerVision/assets/114062987/9df55a43-7351-4eff-94ad-b0b1b4eec4d7)
