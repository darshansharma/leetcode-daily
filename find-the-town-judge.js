//  Question Link:  https://leetcode.com/problems/find-the-town-judge/description
//     Difficulty:  Medium


/**
 * @param {number} n
 * @param {number[][]} trust
 * @return {number}
 */

var findJudge = function(n, trust) {
    if(trust.length === 0){
        if (n === 1) return 1;
        else return -1;
    }
    let canNotBeJudges = [];
    let judges = []
    let judge = -1;
    let people = [];

    for(let i=0; i<trust.length; i++) {
        const trustModel = trust[i];
        canNotBeJudges.push(trustModel[0]);
    }
    
    for(let i=1; i<=n; i++) {
        if(canNotBeJudges.indexOf(i) === -1) {
            judges.push(i);
        }
    }
    judge = judges[0];
    for(let i=0; i<trust.length; i++) {
        const trustModel = trust[i];
        if(trustModel[1] === judge) {
            people.push(trustModel[0]);
        }
    }
    
    for(let i=1; i<=n; i++) {
        if(i !== judge) {
            if(people.indexOf(i) === -1) {
                judge = -1;
                break;
            }
        }
    }
    return judge;
};