#include <stdio.h>
#include <malloc.h>
#include <math.h>

#define ITERATIONS 100
#define epsilon 0.0005		// epsilon is the smoothing factor

// function using Batch Gradient Descent to calculate parameters
double* findParametersBGD(double** TrainingData, int DataCount, int n, double rateConstant) {
	double* parameters = (double*)malloc((n+1)*sizeof(double));
	// initilising parameters all parameters to 0.1
	int i, j, k;
	for(i=0;i<=n;i++)
		parameters[i] = 0.1;
	double SoF[DataCount];
	printf("number of features = %d, number of training samples = %d\n", n, DataCount);
	double sumsquaregrad = 0;
	for(k=0;k<ITERATIONS;k++) {				// performing pre defined number of iterations
		for(i=0;i<DataCount;i++) {
			SoF[i] = parameters[0];
			printf("sof[%d] = %lf\n", i, parameters[0]);
			for(j=0;j<n;j++) {
				printf("sof[%d] += %lf*%lf\n", i, parameters[j+1], TrainingData[i][j]);
				SoF[i] += parameters[j+1]*TrainingData[i][j];
			}
			printf("sum of features of %dth sample = %lf\n", i, SoF[i]);
		}
		for(i=0;i<DataCount;i++)
			printf("SoF[%d] = %lf\n", i, SoF[i]);
		for(i=0;i<=n;i++) {
			printf("calculating %d parameter\n", i);
			double SumGradient = 0;
			for(j=0;j<DataCount;j++) {
				SumGradient += 2*(SoF[j]-TrainingData[j][n])*(i==0?1:TrainingData[j][i-1]);//grad(parameters, TrainingData, DataCount, i, n, j);
			}
			sumsquaregrad += SumGradient*SumGradient;
			parameters[i] -= (rateConstant/(pow(sumsquaregrad, 0.5)+epsilon))*SumGradient;
		}
		for(i=0;i<=n;i++)
			printf("parameters[%d] = %lf\n", i, parameters[i]);
	}

	return parameters;
}

int main() {
	int n, DataCount, i;
	printf("enter number of features: ");
	scanf("%d", &n);
	printf("Enter number of Training Samples: ");
	scanf("%d", &DataCount);
	double** TrainingData = (double**)malloc(DataCount*sizeof(double)), rateConstant;
	printf("enter features and output one by one for all the training Samples\n");
	for(i=0;i<DataCount;i++) {
		TrainingData[i] = (double*)malloc((n+1)*sizeof(double));
		int j;
		for(j=0;j<=n;j++) {
			scanf("%lf", &TrainingData[i][j]);
		}
	}
	printf("Data entered:\n");
	for(i=0;i<n;i++) {
		printf("feature%d\t", i+1);
	}
	printf("output\n");
	for(i=0;i<DataCount;i++) {
		int j;
		for(j=0;j<=n;j++)
			printf("%lf\t", TrainingData[i][j]);
		printf("\n");
	}
	printf("enter rate constant: ");
	scanf("%lf", &rateConstant);
	printf("Beginning Training. Please wait for some time to finish the Training.....\n");
	double *parameters = findParametersBGD(TrainingData, DataCount, n, rateConstant);
	printf("Training of Data is Completed\n");
	printf("--------------------------------------------------------------------------------------------\n");
	printf("Obtained Parameters are:\n");
	for(i=0;i<=n;i++)
		printf("parameter%d\t", i);
	printf("\n");
	for(i=0;i<=n;i++)
		printf("%lf\t", parameters[i]);
	printf("\n");
	printf("--------------------------------------------------------------------------------------------\n");
	while(1) {
		int c;
		printf("enter 1 to Test and 0 to abort\n");
		scanf("%d", &c);
		if(c==0)
			break;
		double output = 0, *testData = (double*)malloc(n*sizeof(double));
		printf("enter Test Data:\n");
		for(i=0;i<n;i++) {
			scanf("%lf", &testData[i]);
			output += testData[i]*parameters[i+1];
		}
		printf("output:\t%lf\n", output);
		free(testData);
	}
	free(parameters);
	for(i=0;i<DataCount;i++)
		free(TrainingData[i]);
	free(TrainingData);
	return 0;
}