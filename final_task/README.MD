# Semantic Segmentation with U-Net on IDD Dataset

## Overview
This project implements semantic segmentation using a custom U-Net model with skip connections in the decoder. The model is trained on the **Indian Driving Dataset (IDD)** to segment road scenes efficiently. The implementation includes data preprocessing, model training, validation, and evaluation. 


                                                            https://i.imgflip.com/8s7ktm.jpg?a484104

I simplified the model as per the feedback and couldnt train it completely, but the the jupyter notebook shows the loss change. The segmented mask is of the previous model. 

## Features
- **Custom U-Net Architecture**: Designed for multi-class segmentation with skip connections.
- **Data Augmentation**: Applied during training to improve generalization.
- **IoU Calculation**: Used to measure segmentation accuracy.
- **Early Stopping**: Stops training when validation loss stops improving.
- **GPU Support**: The model automatically runs on GPU if available.

## Dataset
The model is trained on the **IDD 20K-II dataset**, which contains labeled road scene images. The dataset consists of:
- **Images**: RGB road scene images.
- **Masks**: Corresponding labeled segmentation masks.
- **Classes**: 13 distinct categories (e.g., road, vehicles, pedestrians, etc.).

## Installation
To run this project, install the necessary dependencies:
```bash
pip install torch torchvision numpy opencv-python albumentations matplotlib tqdm
```

## Model Architecture
The U-Net model consists of:
1. **Encoder**: Feature extraction using convolutional layers.
2. **Bottleneck**: Transition layer before upsampling.
3. **Decoder**: Upsampling layers with skip connections to retain spatial details.
4. **Final Layer**: Predicts pixel-wise class probabilities.

## Training Procedure
1. Load the dataset and apply transformations.
2. Train the U-Net model using **CrossEntropy Loss**.
3. Optimize with **Adam optimizer** and learning rate scheduling.
4. Compute **IoU metric** for performance evaluation.

## Evaluation
The model is evaluated using:
- **Intersection over Union (IoU)**: Measures segmentation accuracy.
- **Validation Loss**: Monitors overfitting.

## Inference
Use the trained model to segment new images:
```python
python inference.py --image path/to/image.jpg
```
This will output a segmented mask overlayed on the original image.

## Future Improvements
- Train on a larger dataset for better generalization.




