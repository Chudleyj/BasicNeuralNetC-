#include <iostream>
#include <vector>
using namespace std;

class Neuron;
typedef vector<Neuron> Layer;

class Neuron
{
public:
	Neuron() {};
private:
	double n_outputVal;
};
class NeuralNet
{
public:
	NeuralNet() {};
	NeuralNet(const vector<unsigned> &topology);
	void feedForward(const vector<double> &inputVal) {};
	void backProp(const vector<double> &targetVal) {};
	void getResults(vector <double> &resultsVal) const {};

private:
	vector<Layer> m_layers; //m_layers[layerNum][neuronNum]
};
NeuralNet::NeuralNet(const vector<unsigned> &topology)
{
	unsigned numLayers = topology.size();
	int count = 0;
	for (unsigned layerNum = 0; layerNum < numLayers; layerNum++)
	{
		m_layers.push_back(Layer());
		for (unsigned neuronNum = 0; neuronNum <= topology[layerNum]; neuronNum++)
		{
			m_layers.back().push_back(Neuron());
			count++; 
			cout << "Made neuron " << count <<  endl;
		}
	}
}
int main()
{
	vector<unsigned> topology;

	topology.push_back(3);
	topology.push_back(2);
	topology.push_back(1);

	NeuralNet net1(topology);
	vector<double> inputVal;
	vector<double> targetVal;
	vector<double> resultVal;

	net1.feedForward(inputVal);
	net1.backProp(targetVal);
	net1.getResults(resultVal);

	system("pause");
	return 0;
}