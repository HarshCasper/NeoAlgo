<p align="center">
    <img src="/img/neo_algo.png"><br>
    <img src="https://img.shields.io/github/license/tesseractcoding/neoalgo?style=flat">
    <a href="http://makeapullrequest.com" target="_blank"><img src="https://img.shields.io/badge/PRs-welcome-brightgreen.svg?style=flat" alt="PRs Welcome"></a>
    <img alt="GitHub pull requests" src="https://img.shields.io/github/issues-pr/tesseractcoding/neoalgo">
    <img alt="GitHub issues" src="https://img.shields.io/github/issues/tesseractcoding/neoalgo">
    <img alt="Github All Contributors" src="https://img.shields.io/github/all-contributors/tesseractcoding/neoalgo">
</p>


# Data Encryption Standard Symmetric Key Algorithm 64-bit

## Table Of Contents
- [Description of algorithm](#description-of-algorithm)
- [Classes and Packages](#classes-and-packages)
- [Classes used under current package](#classes-used-under-current-package)
- [Package and Folder structure](#package-and-folder-structure)
- [Execution flow overview](#execution-flow-overview)
- [Execution flow detailed](#execution-flow-detailed)
- [Setup](#setup)
- [Run in Terminal](#run-in-terminal)
- [Run in Eclipse IDE](#run-in-eclipse-ide)

## Description of algorithm

The DES algorithm is the most widely used encryption algorithm in the world, DES has been found vulnerable/breakable against many attacks, reflecting it's a decline in popularity but despite this DES will live in many government and banking for years, due to its successor algorithms Triple-DES, AES, etc, for many years "secret code making" and DES have been synonyms.
<BR />
<BR />
DES was developed by IBM in the 1970s and was based on an earlier design of Horst Feistel, the algorithm was then submitted to NBS(National Bureau of Standards), in 1976 after consultation with NSA(National Security Agency) NBS selected a slightly modified version of the respective algorithm, which was then published as an official Federal Information Processing Standard(FIPS) for the United States of America in 1977.
<BR />
For more detailes please click [here](http://page.math.tu-berlin.de/~kant/teaching/hess/krypto-ws2006/des.htm)

## Classes and Packages

* [__des__](README.md)
  * [DESController.java](DESController.java)
  * [DESCryptographyLogic.java](DESCryptographyLogic.java)
  * [DESCryptographyModels.java](DESCryptographyModels.java)
  * [InitialPermutationLogic.java](InitialPermutationLogic.java)
  * [InverseInitialPermutationLogic.java](InverseInitialPermutationLogic.java)
  * [PBoxLogic.java](PBoxLogic.java)
  * [SBoxLogic.java](SBoxLogic.java)
* [__des.exception__](exception/README.md)
  * [ValidationException.java](exception/ValidationException.java)
* [__des.general__](general/README.md)
  * [GeneralMethods.java](general/GeneralMethods.java)
* [__des.key__](key/README.md)
  * [KeyGenerationModels.java](key/KeyGenerationModels.java)
  * [KeyGenerator.java](key/KeyGenerator.java)
* [__des.validator__](validator/README.md)
  * [ValidatorLogic.java]()

## Classes used under current package

![DES Package Classes and Methods](/img/des/DESPackageClassesAndMethods.png)

## Package and Folder structure

<p align="center">
  <img src="/img/des/DESPackagesAndFolders.gif" >
</p>

## Execution flow overview
![DES Algorithm Execution Flow Overview](/img/des/DESAlgorithmOverview.gif)
## Execution flow detailed
![DES Algorithm Execution Flow Detailed](/img/des/DESAlgorithmDetailed.gif)
## Setup
* Create the folder and package structure mentioned above on your machine
  * Create a folder _des_
  * Download and place following files under "des" folder
    * `DESController.java`
    * `DESCryptographyLogic.java`
    * `DESCryptographyModels.java`
    * `InitialPermutationLogic.java`
    * `InverseInitialPermutationLogic.java`
    * `PBoxLogic.java`
    * `SBoxLogic.java`
  * Create a folder _exception_ under _des_
  * Download and place file `ValidationException.java` under _exception_ folder
  * Create a folder _general_ under _des_
  * Download and place file `GeneralMethods.java` under _general_ folder
  * Create a folder _key_ under _des_
  * Download and place files`KeyGenerationModels.java` and `KeyGenerator.java` under _key_ folder
  * Create a folder _validator_ under _des_
  * Download and place file `ValidatorLogic.java` under _validator_ folder
## Run in Terminal
Suppose you have create the _des_ folder and its hierarchy under `E:\neoalgo\`
* Go to `E:\neoalgo\` in terminal
* `SET CLASSPATH=.;E:\neoalgo`
* For verification of entered CLASSPATH enter `echo %CLASSPATH%`, the CLASSPATH will display in terminal
```bash
 cd des
 cd general
 javac GeneralMethods.java
 cd..
 cd key
 javac *.java
 cd..
 cd exception
 javac ValidationException.java
 cd..
 cd validator
 javac ValidatorLogic.java
 cd..
 javac *.java
 cd..
 java des.DESController
 ```

## Run in Eclipse IDE
* Create a new _Java Project_ in Eclipse
* Copy and Paste the created directy under the `src` folder in eclipse
* Now click on _Run as Java Project_ or press _Alt+Shift+X,J_
