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


	}
}