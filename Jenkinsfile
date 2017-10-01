pipeline{
	agent any

	stages{

		stage('Compiling Stage'){

			steps{
				sh 'c++ -c Test_1.cpp'
			}

		}

		stage('linking Stage'){

			steps{
				sh 'c++ -o target Test_1.o'
			}

		}

		stage('Executing Stage'){

			steps{
				sh './target'
			}

		}

		stage('make clean'){

			steps{
				sh 'make clean'
			}

		}

		stage('make all'){

			steps{
				sh 'make all'
			}
		}

		stage('make run'){

			steps{
				sh './target'
			}
		}

	}
}