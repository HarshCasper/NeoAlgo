$(document).ready(() => {

    /*
     *   An arrow function with 1 parameter and returns a value.
     *   @param {Array} arrayOfCandidates contains a list of candidates
     *   @return {number} majority candidate value selected by the algorithm
     *   
     *   This function is used to calculate the candidate which has the 
     *   majority number of votes, this algorithm was propossed by Boyer Moore's.
     */
    const selectCandidate = (arrayOfCandidates) => {

        var majorityVotes = 1; //contains the vote number of the candidate
        var majorityCandidate = arrayOfCandidates[0]; //contains current majority candidate

        for (var i = 1; i < arrayOfCandidates.length; i++) //Iterates through the list of candidates
        {

            /*
             * checks whether the current candidate value is 
             * same as of it's preceding one
             */
            if (majorityCandidate == arrayOfCandidates[i]) {
                majorityVotes++;
            } else {
                majorityVotes--;
            }

            /*
             * If majorityVotes deduct to 0 then a new candidate 
             * is assigned and the value of majorityVotes is reset to 1
             */
            if (majorityVotes <= 0) {
                majorityVotes = 1; //Resetting value of majorityVotes
                majorityCandidate = arrayOfCandidates[i]; //Assigning new candidate
            }
        }
        return majorityCandidate; //Returns MajorityCandidate selected by the algorithm
    }

    /*
     *  An arrow function with 2 parameters and returns a value
     *  @param {Array} arrayOfCandidates contains a list of candidates
     *  @param {number} selectedCandidate the selected candidate by the Boyer Moore's Algorithm
     *  @return {boolean} verifies and returns that the given candidate is Majority Candidate or not
     * 
     * This function is used to verify that the given candidate which was selected, is actually a
     * valid candidate and statisfies the need of having votes greater than 50% of the length of list.
     */
    const validateSelectedCandidate = (arrayOfCandidates, selectedCandidate) => {

        var countOfSelectedCandidate = 0; //counts number of seats earned of the candidate

        //Iterates through the list of candidates
        arrayOfCandidates.forEach(candidate => {

            /*
             *   If the selected candidate by the algorithm has the value equal
             *   to the current element value then the countOfSelectedCandidate
             *   is incremented by 1
             */
            if (selectedCandidate == candidate) {
                countOfSelectedCandidate++;
            }
        });
        /*
         *   Verifies that the total count of candidate 
         *   is greater than 50% of the total length of the list
         * 
         *  returning true signifies that the selected candidate is a legit candidate and has majority votes
         *  returning false signifies that the selected candidate is not a legit candidate and no majority candidate is detected in the list
         */
        if (countOfSelectedCandidate > (arrayOfCandidates.length / 2)) {
            return true;
        }
        return false;
    };

    /*
     *  An arrow function with 1 parameter and no return value
     *  @param {Array} listOfCandidates contains a list of candidates 
     * 
     *  This function acts as the main entry point for the execution flow
     */
    const main = (listOfCandidates) => {
        var selectedCandidate = selectCandidate(listOfCandidates); //Fetches value of the selected candidate
        var result = validateSelectedCandidate(listOfCandidates, selectedCandidate); //Passes the candidate for verification and gets the result
        if (result) {
            console.log(selectedCandidate + " Has The Majority Number Of Votes")
        } else {
            console.log("No Majority Candidate Detected")
        }
    }

    //Declaration of list of candidates
    var listOfCandidates = new Array(3, 3, 3, 3, 1, 1, 1, 3, 2);
    //Calls main function for starting execution process
    main(listOfCandidates);

});
