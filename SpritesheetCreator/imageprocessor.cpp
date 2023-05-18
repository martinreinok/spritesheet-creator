#include "imageprocessor.h"
#include <set>

using namespace cv;

ImageProcessor::ImageProcessor()
{

}

QVector<cv::Mat> ImageProcessor::get_images_from_table(QTableWidget * table)
{
    QVector<cv::Mat> images;
    for (int row = 0; row < table->rowCount(); row++) {
        std::string imagePath = table->item(row, 1)->text().toStdString();
        cv::Mat image = cv::imread(imagePath, cv::IMREAD_UNCHANGED);
        if (!image.empty()) {
            images.push_back(image);
        }
    }
    return images;
}

bool ImageProcessor::validate_image_size(QVector<cv::Mat> opencv_images)
{
    if (opencv_images.isEmpty()){
        return false;
    }
    std::set<int> image_dimensions_set;
    for (const auto& image : opencv_images) {
        image_dimensions_set.insert(image.size[0]);
        image_dimensions_set.insert(image.size[1]);
    }
    return image_dimensions_set.size() == 1;
}

cv::Mat ImageProcessor::create_spritesheet(int rows, int columns, QVector<cv::Mat> opencv_images){
    int image_height = opencv_images[0].size[0];
    int image_width = opencv_images[0].size[1];
    cv::Mat spritesheet(image_height * rows, image_width * columns, CV_8UC4, cv::Scalar(0, 0, 0, 0));
    int current_row = 0;
    int current_column = 0;
    for (const cv::Mat& image : opencv_images) {
        image.copyTo(spritesheet(cv::Rect(current_column*image_width,
                                          current_row*image_height,
                                          image_width, image_height)));
        current_column++;
        if (current_column == columns){
            current_row++;
            current_column = 0;
        }
    }
    return spritesheet;
}

void ImageProcessor::opencv_save_image(cv::Mat opencv_image, QString file_destination)
{
    cv::imwrite(file_destination.toStdString(), opencv_image);
}

