"""
created by: AdhilUsman
created on: 28-06-2021
This program simulates a coin flip and outputs heads or tails. It is impossible to have 100 percentage randomness in classical world. The modules like randomm only creates pseudo randomness which means after a while there will be a pattern. Quantum world is 100 percentage random and probabilistic. So the ouutput of this program will be random and will have equal probability.
"""



# import necessary modules
from qiskit import QuantumRegister, ClassicalRegister, QuantumCircuit

# create a quantum circuit
q = QuantumRegister(1)
c = ClassicalRegister(1)
circuit = QuantumCircuit(q, c)

#create a super position state
circuit.h(q)

#measure the state
circuit.measure(q,c)


#run code in a simulator

from qiskit import BasicAer, execute

backend = BasicAer.get_backend('qasm_simulator')
job = execute(circuit, backend, shots=5, memory=True)

result = job.result().get_memory()
print(result)
for output in result:
    if output=='0':
        print('HEADS')
    else:
        print('TAILS')


# uncomment to run in an actual quantum computer

"""
from qiskit import IBMQ

IBMQ.load_accounts()

backend = IBMQ.get_backend('ibmq_16_melbourne')
job = execute(circuit, backend, shots=5, memory=True)
for output in job.result().get_memory():
    if output=='0':
        print('HEADS\n')
    else:
        print('TAILS\n')
""" 