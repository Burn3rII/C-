#include "headers/sin.h"
#include "headers/stp.h"
#include "headers/gau.h"
#include "headers/tsdata.h"
#include "headers/knn.h"
#include <iostream>
#include <vector>
using namespace std;

int main() {
    TimeSeriesDataset trainData(false, true), testData(false, false);
    GaussianGenerator gsg;
    SinWaveGenerator swg;
    StepGenerator stg;
    
    vector<double> gaussian1 = gsg.generateTimeSeries(11);
    trainData.addTimeSeries(gaussian1, 0);
    cout << "Série gaussienne 1 :" << endl;
    TimeSeriesGenerator::printTimeSeries(gaussian1);
    cout << endl;

    vector<double> gaussian2 = gsg.generateTimeSeries(11);
    trainData.addTimeSeries(gaussian2, 0);
    cout << "Série gaussienne 2 :" << endl;
    TimeSeriesGenerator::printTimeSeries(gaussian2);
    cout << endl;

    vector<double> sin1 = swg.generateTimeSeries(11);
    trainData.addTimeSeries(sin1, 1);
    cout << "Série sinusoidale 1 :" << endl;
    TimeSeriesGenerator::printTimeSeries(sin1);
    cout << endl;

    vector<double> sin2 = swg.generateTimeSeries(11);
    trainData.addTimeSeries(sin2, 1);
    cout << "Série sinusoidale 2 :" << endl;
    TimeSeriesGenerator::printTimeSeries(sin2);
    cout << endl;

    vector<double> step1 = stg.generateTimeSeries(11);
    trainData.addTimeSeries(step1, 2);
    cout << "Série step 1 :" << endl;
    TimeSeriesGenerator::printTimeSeries(step1);
    cout << endl;

    vector<double> step2 = stg.generateTimeSeries(11);
    trainData.addTimeSeries(step2, 2);
    cout << "Série step 2 :" << endl;
    TimeSeriesGenerator::printTimeSeries(step2);
    cout << endl;
    
    vector<int> ground_truth;
    testData.addTimeSeries(gsg.generateTimeSeries(11));
    ground_truth.push_back(0);
    testData.addTimeSeries(swg.generateTimeSeries(11));
    ground_truth.push_back(1);
    testData.addTimeSeries(stg.generateTimeSeries(11));
    ground_truth.push_back(2);
    
    KNN knn_1(1, "dtw");
    cout << knn_1.evaluate(trainData, testData, ground_truth) << endl;
    KNN knn_2(2, "euclidean_distance");
    cout << knn_2.evaluate(trainData, testData, ground_truth) << endl;
    KNN knn_3(3, "edr");
    cout << knn_3.evaluate(trainData, testData, ground_truth) << endl;
}
