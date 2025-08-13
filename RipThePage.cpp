#define MINIAUDIO_IMPLEMENTATION
#include <iostream>
#include <string>
#include <limits>
#include <random>
#include <ctime>



using namespace std;

// Zen's Character Blueprint

class Zen {
private: // Variables can only be directly accessed by functions
     int currentHP;
     int maxHP;
     int originBar;
     int maxOriginBar;
     int bandages;



public: // functions that you can use outside
     Zen(int health, int origin, int numBandges) {
          currentHP = health;
          maxHP = health;
          originBar = origin;
          maxOriginBar = origin;
          bandages = numBandges;
     }


     // Function for health reduction
     void takeDamage(int damage) {
     currentHP -= damage;
     if (currentHP < 0) {
          currentHP = 0; // Makes HP remain 0
     }
}

     // Function for healing
     void heal(int amount) {
               currentHP += amount;
               if (currentHP > maxHP) {
                    currentHP = maxHP;
               }
          }

     bool hasEnoughOrigin(int cost) {
     return originBar >= cost;
}

     void useOrigin(int cost) {
     originBar -= cost;
}

     void gainOrigin(int amount) {
          originBar += amount;
          if (originBar > maxOriginBar) {
               originBar = maxOriginBar;
          }
     }

     bool hasBandages() {
          return bandages > 0;
     }

     void useBandages() {
          bandages--;
     }

     bool isAlive() {
          return currentHP > 0;
     }

     int getCurrentHP() const { return currentHP; }
     int getMaxHP() const { return maxHP; }
     int getOriginBar() const { return originBar; }
     int getMaxOriginBar() const { return maxOriginBar; }
     int getBandages() const { return bandages; }
};

class Brute {
private:
     int currentHP;
     int maxHP;
public:
     Brute(int health) {
          currentHP = health;
          maxHP = health;
     }
     void takeDamage(int damage) {
          currentHP -= damage;
          if (currentHP < 0) {
               currentHP = 0;
          }
     }
     bool isAlive() {
          return currentHP > 0;
     }
     int getCurrentHP() const { return currentHP; }
     int getMaxHP() const { return maxHP; }
};

const int ZEN_START_HP = 2000;
const int BRUTE_START_HP = 5000;
const int ORIGIN_START_BAR = 2000;
const int BANDAGES_START_COUNT = 3;

const int ZEN_BANDAGE_HEAL = 2000;
const int BRUTE_DEFAULT_DAMAGE = 200;

// --- Player Attack Stats ---
const int JAKE_ATTACK_DAMAGE = 600;
const int JAKE_ATTACK_ORIGIN_COST = 300;

const int VERGIL_ATTACK_DAMAGE = 1200;
const int VERGIL_ATTACK_ORIGIN_COST = 1500;

const int GUNS_ATTACK_DAMAGE = 750;
const int GUNS_ATTACK_ORIGIN_COST = 500;

const int FISTS_ATTACK_DAMAGE = 400;

// --- Brute Attack Stats ---
const int BRUTE_SPIKES_DAMAGE = 300;
const int BRUTE_SPIKES_ORIGIN_GAIN = 350;

const int BRUTE_SCHIZO_DAMAGE = 750;
const int BRUTE_SCHIZO_ORIGIN_GAIN = 550;

const int BRUTE_BLAST_DAMAGE = 500;
const int BRUTE_BLAST_ORIGIN_GAIN = 300;


void printBattleUI(const Zen& zenChar, const Brute& bruteChar) {
     cout << "\n[================== BATTLE READY! ==================] \n";
     cout << "Zen's Health: " << zenChar.getCurrentHP() << "/" << zenChar.getMaxHP() << endl;
     cout << "[ORIGIN] Mutation: " << zenChar.getOriginBar() << "/" << zenChar.getMaxOriginBar() << endl;
     cout << "Brute Logidite's Health: " << bruteChar.getCurrentHP() << "/" << bruteChar.getMaxHP() << endl;
     cout << "[===================================================] \n";
}

// Making of the main Program



int main() {
     // Initializing the audio engine and audio setup
     // Input variables for intro
     srand(time(0));
     // Declare the random number generator and distribution
     mt19937 rng(time(0));
     uniform_int_distribution<int> bruteAttackChanceDist(1, 100);

     string intro;

     Zen zen(ZEN_START_HP, ORIGIN_START_BAR, BANDAGES_START_COUNT);
     Brute brute(BRUTE_START_HP);

     // Game intro scene

     cout << "A tired Zen peers across the destroyed city skyline. The sun shining through dense dark clouds, as if heaven itself has come down for judgement. \n"
          << "The ground beneath him is grey, blood splattered, and covered with multiple bodies of horrifying analog alien monsters that he had killed earlier. \n"
          << "Input any key to continue: \n";
     cin >> intro;
     cout << string(3, '\n');

     cout  << "\"Alright, 5 more to go. I better get going before the probes come,* he thinks to himself.\" \n"
           << "He stomps on the ground, particles of rock and earth seem to erupt from underneath and the ground cracks with immense force, \n"
           << "as he dashes away at a blinding speed with single steps. \n"
           << "Input any key to continue: \n";
     cin >> intro;
     cout << string(3, '\n');

     // Seperated cout per Paragraph, choice variables for y/n
     cout << "He cycles through a mental list to keep his weapons accounted for, taking note for the amount of stamina and energy he has left,\n"
          << "just in case he needs to fight any fodder, Assault Rifles, Big Limbs, Spectral Swords, Hand Maces, Dual Wield Glo- \n"
          << ">>> ` **CRASH**  <<< \n"
          << "Input any key to continue: \n";

     cin >> intro;
     cout << string(3, '\n');

     cout << "A gigantic cylinder blocks his view as it punches into his chest, an excruciating pain fills his body, and he goes flying.\n"
          << "'well, crap, looks like i missed one', he thinks to himself, briskly gaining aerial velocity like a damn bullet. \n"
          << "He finally lands (crashes) on a wall of concrete from a decimated residential building, not unlike the rest of the buildings in the area. \n"
          << "Input any key to continue: \n";
     cin >> intro;
     cout << string(3, '\n');

     cout << "A dark complexion individual with a mouthless face, but piercing eyes, large chest, but a thin torso, long slender arms with enough strength to crush a stickman skull, \n"
          << "with a single snap of their fingers. He is a Brute Logidite. The alien species that invaded Manila, Philippines. \n"
          << "Zen was pretty sure that he had fended off the hordes of alien soldiers that were in the area, like he saw earlier. \n"
          << "Input any key to continue. \n";
     cin >> intro;
     cout << string(3, '\n');


     cout << "The alien monster, stretches out his arms and lets out an unworldly cry akin to a banshee. He stomps his legs and charges at Zen. \n"
          << "Zen gets up from the rubble and stretches out his arms. A determined look on his face. \n"
          << "Input any key to continue. \n";
     cin >> intro;
     cout << string(3, '\n');


     // UI for Battle
     while (zen.isAlive() && brute.isAlive()) {
          // Using the isAlive() method
          printBattleUI(zen, brute); // Pass the actual Zen and Brute objects

          cout << "\"ARSENAL!\"" << endl;
          cout << "(1) Jake The Dog Wannabe (-" << JAKE_ATTACK_ORIGIN_COST << " ORIGIN | " << JAKE_ATTACK_DAMAGE << " Damage ) \n"
               << "(2) I am the storm that is aprooooooachinggg (-" << VERGIL_ATTACK_ORIGIN_COST << " ORIGIN | " << VERGIL_ATTACK_DAMAGE << " Damage) \n"
               << "(3) Guns Ablazing! (-" << GUNS_ATTACK_ORIGIN_COST << " ORIGIN | " << GUNS_ATTACK_DAMAGE << " Damage) \n"
               << "(4) imma fist yo ass bruh (" << FISTS_ATTACK_DAMAGE << " Damage) \n"
               << "(5) Slap a bandage on that ho (" << zen.getBandages() << " Bandages left!)" << endl; // Use getter



          int weaponChoice;
          cout << "Choose your weapon: (1), (2), (3), (4), (5) \n";
          cin >> weaponChoice;
          // Battle outcomes based on weapons and the switch function

          switch (weaponChoice) {
               // Stretchy limbs and mace hands attack based on Jake the Dog, Average damage, low use of ORIGIN Bar
               case 1: {
                    if (zen.hasEnoughOrigin(JAKE_ATTACK_ORIGIN_COST)) { // Use Zen's method
                         zen.useOrigin(JAKE_ATTACK_ORIGIN_COST);         // Use Zen's method
                         brute.takeDamage(JAKE_ATTACK_DAMAGE);
                         string ZenJakeContinue;

                         cout << "Zen stretches out his arms, fists closed. His arms stretch and fists grow to an absurd rate, like rubbery gigantic wrecking balls. \n"
                              << "Swiftly, in a slingshot fashion, he makes thorns grow out of their ends, creating gigantic maces on both his hands. \n"
                              << "He closes and releases them with a deadly mix of strength and speed.\n"
                              << "Input any key to continue: \n";
                         cin >> ZenJakeContinue;
                         cout << string(3, '\n');

                         cout << "The Brute counters by jumping out of the way just in time, leaving a cloud of dust and concrete, still running towards Zen. \n"
                              <<  "A Direct Miss! \n"
                              <<  "Frustrated, Zen lurches forwards and starts spinning, turning himself into a lethal organic beyblade. \n"
                              <<  "Just in time, The brute dashes forward with great swiftness and gets hit by one of his fists. \n"
                              <<  "Input any key to kick its ass!: \n";
                         cin >> ZenJakeContinue;
                         cout << string(3, '\n');

                         cout << ">>> **CRASH!** <<< \n"
                              << ">>> **THWACK!** <<< \n"
                              << ">>> **KRUNCH!** <<< \n"
                              << ">>> 3 BRUTAL HITS! <<< \n"
                              << "Input any key to continue: \n";
                         cin >> ZenJakeContinue;
                         cout << string(3, '\n');

                         cout << "The brute is flung into a tree and gets impaled by blood-stained branch. It lets out another scream as it slowly lundges forward, taking the branch out of its abdomen. \n"
                              << "A black swirling liquid drips onto its visible bones, covering them, and replaces the gaping hole in its stomach. \n"
                              << "Input any key to ready yourself: \n";
                         cin >> ZenJakeContinue;
                         cout << string(3, '\n');
                    } else {
                         cout << "You dumbass! You don't have enough [ORIGIN] Mutation for that! \n";
                         cout << string(3, '\n');
                         continue;
                    }
                    break;
               }

               case 2: {
                    /* Vergil-inspired attack, telekinetic sword projectiles. High ORIGINBar Use, Highest Damage
                     * 1500 ORIGIN - 1200 DAMAGE */

                    if (zen.hasEnoughOrigin(VERGIL_ATTACK_ORIGIN_COST)) {
                         zen.useOrigin(VERGIL_ATTACK_ORIGIN_COST);
                         brute.takeDamage(VERGIL_ATTACK_DAMAGE);
                         string ZenVergilContinue;

                         cout << "Zen swiftly gets up from the rubble and stretches out his right arm. His hand envelops with a deep blue aura that bleeds into his body frame. \n"
                              << "His entire body ignites with fiery blue aura. He performs a pointing gesture with his right hand as multiple apparitions of ghostly greatswords appear around him, \n"
                              << "pointed towards the alien. \n"
                              << "Input any key to continue: \n";
                         cin >> ZenVergilContinue;
                         cout << string(3, '\n');

                         cout << "The swords glow sharply as Zen yells, \"Release!\"\n"
                              << "Ripping through the air with straight percision and lethal energy, the swords come zooming onto the rapidly approaching alien. \n"
                              << "Input any key to SHIVV HIS ASS! \n";
                         cin >> ZenVergilContinue;
                         cout << string(3, '\n');

                         cout << ">>> **SHHNK!** <<< \n"
                              << ">>> **SHHNK!** <<< \n"
                              << ">>> **CHRNK!** <<< \n"
                              << ">>> **CHRNK!** <<< \n"
                              << ">>> ALL OF THEM HIT! <<< \n"
                              << "Input any key to continue: \n";

                         cin >> ZenVergilContinue;
                         cout << string(3, '\n');

                         cout << "The brute arches its back in pain, gurgling a grotesque guttural scream as all of the swords suddenly eject from it's body, disapparating in an instant. \n"
                              << "Its conniving bloodlusted yet emotionless eyes are locked on Zen. He realizes it hasn't even blinked once. \n"
                              << "Input any key to ready yourself: \n";
                         cin >> ZenVergilContinue;
                         cout << string(3, '\n');
                         break;

                    } else {
                         cout << "You dumbass! You don't have enough [ORIGIN] Mutation for that! \n";
                         cout << string(3, '\n');
                         continue;
                    }
               }

               case 3: {
                    // A blazing gun barrage with a surprise finish *wink wink*

                    if (zen.hasEnoughOrigin(GUNS_ATTACK_ORIGIN_COST)) {
                         zen.useOrigin(GUNS_ATTACK_ORIGIN_COST);
                         brute.takeDamage(GUNS_ATTACK_DAMAGE);

                         string ZenGunsContinue;

                         cout << "Zen refocuses and smiles as he whips out 2 desert eagles, one on each of his hands. \n"
                              << "He spins forward and stops as a stance, walking forward, while shooting- \n"
                              << ">> **BANG! BANG! BANG!** <<\n"
                              << "Input any key to continue: \n";
                         cin >> ZenGunsContinue;
                         cout << string(3, '\n');

                         cout << "Tons of shells drop on the ground with a satisfying click. Although all of them hit the target, each of the bullets seems to leave the alien unaffected. \n"
                              << "\"Looks like we need heavier artillery!\" \n"
                              << "Input any key to bring out the big guns: \n";
                         cin >> ZenGunsContinue;
                         cout << string(3, '\n');

                         cout << "Zen throws the handguns on the ground, as he pulls out 2 FN-SCAR Assault Rifles seemingly out of nowhere. \n"
                              << "Zen grips the Assault Rifles tightly in both hands, and imbues some of his [ORIGIN] mutation into the guns. \n"
                              << "\"Let's put a little back into it.\" Zen says, as the alien continues slowly approaching. \n"
                              << "Input any key to start bullet hell!: \n";
                         cin >> ZenGunsContinue;
                         cout << string(3, '\n');

                         cout << ">>> ***DRGRGRGRGRGRG!*** <<< \n"
                              << "Red streaks cut through the air as the rushing bullets now have a red [ORIGIN] glow. The Brute tries desperately to shrug them off while charging. \n"
                              << "Eventually, the Brute starts getting overwhelmed by the barrage of firearm frenzy, and stumbles back! \n"
                              << "\"NOW TRY THIS!\" \n"
                              << "Input any key to blast his ass!: \n";
                         cin >> ZenGunsContinue;
                         cout << string(3, '\n');

                         cout << "Zen throws the Assault Rifle at the Brute, and pulls out a freaking RPG from the air. He prepares to launch a rocket with exact and true percisio- \n"
                              << "\"KABOOM MOTHERFUCKER!\" \n"
                              << ">>>  **BOOM**  <<< \n"
                              << ">>>  **STRAIGHT HIT!**  <<< \n"
                              << "The Brute emerges from a cloud of smoke, coming from its abdomen, half of his chest has been blown to bits. \n"
                              << "However, pieces of black rope stemming from his body seem to be connecting and repairing its wound. \n"
                              << "Input any key to ready yourself: \n";
                         cin >> ZenGunsContinue;
                         cout << string(3, '\n');
                         break;

                    } else {
                         cout << "You dumbass! You don't have enough [ORIGIN] Mutation for that! \n";
                         cout << string(3, '\n');
                         continue;
                    }
               }

               case 4: {
                    brute.takeDamage(FISTS_ATTACK_DAMAGE);
                    string ZenFistsContinue;

                    cout << "Zen's eyes flash with a red glare, as he transitions from laying in the rubble to front flipping into an attacking stance. He bares his fists in front of him. \n"
                         << "With a flash and rubble sent everywhere, he dashes and attacks the alien head-on. The both of them collide with a deafening crunch. \n"
                         << "The earth beneath them splitting and crumbling, as their fists force themselves on each other. \n"
                         << "Input any key to continue: \n";
                    cin >> ZenFistsContinue;
                    cout << string(3, '\n');

                    cout << "They trade fast, quick, but powerful blows, with each one doing seemingly no damage, but manifesting gigantic shockwaves that blows away rocks, trees, and even nearby cars. \n"
                         << "Zen suddenly goes low by folding his knees, and kicking upwards, launching the Brute into the sky, stunning him. \n"
                         << "He jumps upwards, while punching the brute dealing 5 successful blows. \n"
                         << "Input any key to beat his ass! \n";
                    cin >> ZenFistsContinue;
                    cout << string(3, '\n');

                    cout << ">>>  ***BAM BAM BAM BAM POW!***  <<< \n"
                         << "Still midair, He puts both of his hands together to deal a shocking downwards blow to the Brute. \n"
                         << "The Brute lands with a deadly cracking sound, as the concrete beneath him splits and forms a crater around itself. A part of his abdomen has been smashed like a flat pancake. \n"
                         << "On the other hand, Zen lands with almost humorous cat-like grace. \n"
                         << "Input any key to continue: \n";
                    cin >> ZenFistsContinue;
                    cout << string(3, '\n');
                    break;
               }

               case 5: {

                    if (zen.hasBandages()) { // Use Zen's methods
                         zen.useBandages();
                         zen.heal(ZEN_BANDAGE_HEAL);

                         string ZenHealContinue;

                         cout << "Barely dodging one of the alien's brute's attacks, Zen flips over a vehicle thrown by The Brute, \n"
                              << "and slashes it midair with his Annhilation Sword, cutting it in half while kicking it back at The Brute. \n"
                              << "The Brute jumps to the side, avoiding the projectile. During said distraction, Zen swiftly spins around and whips out a bandage from his pocket, sticking it to hand. \n"
                              << "Input any key to continue: \n";
                         cin >> ZenHealContinue;
                         cout << string(3, '\n');

                         cout << "**SHHZZT!** \n"
                              << "The bandage gets absorbed, almost pulled into his skin. Zen stretches his arms and opens his eyes, feeling energized. He feels all of his wounds starting to hurt less. \n"
                              << "Tendons, muscle, and skin stitch together and melt into one, once again. Cracking his neck and shaking his hands, he readies himself for attack. \n"
                              << "Input any key to continue: \n";
                         cin >> ZenHealContinue;
                         cout << string(3, '\n');
                         break;
                    } else {
                         cout << "You dumbass! You don't have enough [ORIGIN] Mutation / Bandages for that! \n";
                         cout << string(3, '\n');
                         continue;
                    }
               }

               default: {
                    string ConfusedZen;

                    cout << "\"Wait, player, i don't understand what you're sayi-\"\n"
                         << ">>> **KRUNCH!** <<< \n"
                         << "Zen gets rammed with a force that feels like a Ferrari F1 crashing into you, driven by a bull on crack. \n"
                         << "His eyes pop out and the air in his chest forces out like a smashed balloon. \n"
                         << "Input any key to continue: \n";
                    cin >> ConfusedZen;
                    cout << string(3, '\n');

                    cout << "The Brute grabs Zen and drags him across the ground, gravel and rubble building up behind him. \n"
                         << "It flings him up into the air and before Zen can react, The Brute swiftly punches Zen, sending him flying straight into a construction crane, \n"
                         << "shards of glass and shrapnel getting everywhere. \n"
                         << "Steadying himself and flipping forwards, Zen gets ready for another attack. \n"
                         << "Input any key to continue: \n";
                    cin >> ConfusedZen;
                    cout << string(3, '\n');

                    zen.takeDamage(BRUTE_DEFAULT_DAMAGE);
                    break;
               }
          }



          if (zen.isAlive()) {
               cout << ">>> **ENEMY TURN** <<< \n";
               int bruteAttackRoll = bruteAttackChanceDist(rng);
               int bruteAttack;

               if (bruteAttackRoll <= 30) {
                    bruteAttack = 1;
               } else if (bruteAttackRoll <= 60) {
                    bruteAttack = 2;
               } else if (bruteAttackRoll <= 80) {
                    bruteAttack = 3;
               } else {
                    bruteAttack = 4;
               }

               switch (bruteAttack) {

                    case 1: {
                         zen.takeDamage(BRUTE_SPIKES_DAMAGE);
                         zen.gainOrigin(BRUTE_SPIKES_ORIGIN_GAIN);
                         string BruteSpikesContinue;

                         cout << "With blistering speed, the alien seems to disappear from Zen's sight. He looks around, confused and searching around for it. \n"
                              << "He looks behind him and- \n"
                              << "He comes face to face with The Brute! Long black spikes come out from the alien's stomach and rush out towards Zen.\n"
                              << "Input any key to continue: \n";
                         cin >> BruteSpikesContinue;
                         cout << string(3, '\n');

                         cout << "Zen manages to dash out of the way, and starts sprinting sonic-style away from the bullets, leaving a neon red dust trail. \n"
                              << "One of the spikes suddenly changes course and homes onto Zen with a blinding speed. \n"
                              << "He tries to imbue his legs with more [ORIGIN] to gain more speed, but- \n"
                              << "Input any key, brace for impact! \n";
                         cin >> BruteSpikesContinue;
                         cout << string(3, '\n');

                         cout << ">>> **SHHNK!** <<< \n"
                              << "It sinks into Zen's shoulder! He gasps and abruptly stops, panting while he tends to it. \n"
                              << "Grasping onto his shoulder, he removes it from his side. Zen retracts and returns his hands to ready for another attack. \n"
                              << "(-300 HP! +350 ORIGIN!) \n"
                              << "Input any key to ready for attack: \n";
                         cin >> BruteSpikesContinue;
                         cout << string(3, '\n');
                         break;
                    }

                    case 2: {
                         zen.takeDamage(BRUTE_SCHIZO_DAMAGE); // Corrected
                         zen.gainOrigin(BRUTE_SCHIZO_ORIGIN_GAIN);
                         string BruteSchizoContinue;

                         cout << ">>> **ENEMY TURN** <<< \n"
                              << "Zen stands up and pulls out a desert eagle, shooting the alien, still unaffected. \n"
                              << "He imbues [ORIGIN] into his body to teleport behind the alien, readying an attack. \n"
                              << "\"Blink.\" \n"
                              << "Input any key to teleport!: \n";
                         cin >> BruteSchizoContinue;
                         cout << string(3, '\n');

                         cout << "He suddenly appears right behind the alien, and does a quick kick to its legs, but in the blink of an eye. \n"
                              << "The Brute disappears. He looks around confused. \n"
                              << "Input any key to.. wait what happened?: \n";
                         cin >> BruteSchizoContinue;
                         cout << string(3, '\n');

                         cout << "The sky turns black. The sun's color becomes a muted red. Zen can't see anything, except a few meters infront of him. \n"
                              << "Pure screeching static fills his ears, which he rushes to cover. \n"
                              << "Suddenly The Brute appears infront of him....and another.....and yet another. \n";
                         cin >> BruteSchizoContinue;
                         cout << string(3, '\n');

                         cout << "Until Zen is surrounded by what looks like 7 clones of the same brute, their eyes unleaving their glances on him. \n"
                              << "Zen assumes a defensive stance as he tries to project a protective field of [ORIGIN] energy around him- \n"
                              << ">>> **SHHNK!** <<< \n"
                              << "Input any key to continue: \n";
                         cin  >> BruteSchizoContinue;
                         cout << string(3, '\n');

                         cout << "All 7 of the Brutes stab Zen with their bare hands, pushing their fists into his innards. \n";
                         cout << "The pain is flaming inside of him and only an agonized scream escapes his mouth. \n"
                              << "In the next blink of an eye, everything seems to come back to normal, The Brute still watching infront of him, intently. \n"
                              << "Zen brushes dust of his chest, still in shock from the attack. \n"
                              << "Input any key to ready for attack: \n";
                         cin  >> BruteSchizoContinue;
                         cout << string(3, '\n');
                         break;
                    }

                    case 3: {
                         zen.takeDamage(BRUTE_BLAST_DAMAGE);
                         zen.gainOrigin(BRUTE_BLAST_ORIGIN_GAIN);

                         string BruteBlastContinue;

                         cout << "The Brute starts growing to a gargantuan size, leaving Zen akin to the size of a short pug, compared to a human. \n"
                              << "Its fists lift and pound around him, sending earth in all directions. Zen narrowly avoids all of them. \n"
                              << ">>> **BSSSHH!** <<< \n"
                              << ">>> **CRACK!** <<< \n"
                              << "Input any key to continue: \n";
                         cin  >> BruteBlastContinue;
                         cout << string(3, '\n');

                         cout << "The Brute sets his arms on his sides, preparing a great attack. The Brute's head contorts, and it seems to split into half, opening a gaping maw. \n"
                              << "Gigantic amounts of dark energy come out from his jaw, blasting out of his mouth, decimating everything in its path.  \n"
                              << "Input any key to continue: ";
                         cin  >> BruteBlastContinue;
                         cout << string(3, '\n');

                         cout << "Zen tries to avoid the blast, dashing when necessary to avoid getting (toasty!) turned into ash like the ground beneath him. \n"
                              << "Suddenly, he notices a pattern and attempts to work around it, slowly getting closer and closer, to the behemoth of an alien, trying to land a critial hit until- \n"
                              << ">>> **ZAAAM!** <<< \n";
                         cin  >> BruteBlastContinue;
                         cout << string(3, '\n');

                         cout << "From the Brute's maw comes a gigantic energy blast, that causes a grand explosion in the middle of their battleground. \n"
                              << "This causes the energy blast to split into multiple energy missiles, homing onto Zen. \n"
                              << ">> **BRACKSH* << \n"
                              << ">>  **BOCCSH**  << \n"
                              << "Input any key to asses damage: \n";
                         cin  >> BruteBlastContinue;
                         cout << string(3, '\n');

                         cout << "They all hit! Massive Damage! \n"
                              << "In the next blink of an eye, everything seems to come back to normal, The Brute still watching infront of him, intently. \n"
                              << "Zen gets up from the ground, and brushes dust of his chest, still in shock from the attack. \n"
                              << "Input any key to ready for attack: \n";
                         cin  >> BruteBlastContinue;
                         cout << string(3, '\n');
                         break;
                    }
                    default: {
                         string BruteDefault;

                         cout << "The Brute stands infront of Zen, the dust clearing after the brisk attack of the latter. \n"
                              << "Its eyes locked on Zen once again as the both of them remain stagnant. \n"
                              << "Not one of them makes the first move. Not one of them budges.  \n"
                              << "Input any key to ready for any attack: \n";
                         cin >> BruteDefault;

                         cout << "Suddenly, the alien makes a fist on his hand and Zen flinches. Still, It remains stagnant, almost curious. It might be studying Zen for all we know. \n"
                              << "The Brute seems to nod and assumes a standing stance. \n"
                              << "Input any key to continue: \n";
                         cin >> BruteDefault;
                    }
               }
          }
          if (!brute.isAlive()) {
               string ZenWin;

               cout << "Running and avoiding the blasts that come out from The Brute's mouth, \n"
                    << "Zen summons out his Annhilation Mutation Sword and dashes towards The Brute, and performs multiple slices to Its body.\n"
                    << "Input any key to slash his guts out!: \n";
               cin >> ZenWin;
               cout << string(3, '\n');


               cout << "Although The Brute is consistently being barraged with slices, it does little to damage itself. \n"
                    << "Zen flips back and musters all of his [ORIGIN] Mutation into his sword. \n"
                    << "Rocks from the ground start levitating, rubble, shrapnel, bodies, cars, and wreckage start moving away from Zen as a blinding red aura surrounds him..\n"
                    << "Input any key to execute. \n";
               cin >> ZenWin;
               cout << string(3, '\n');

               cout << "Zen lunges with inhuman and impossible speed at The Brute, churning all of its ligaments and limbs into cutting board fodder. \n"
                    << "Finally, Zen grabs the blade and forces it onto The Brute's neck, dealing one final slash! \n"
                    << "The head of the Brute rolls down onto the ground. It is finally defeated. \n"
                    << "Input any key to claim victory! \n";
               cin >> ZenWin;
               cout << string(3, '\n');

               cout << "Zen lifts a finger towards the alien's body, and with a quick energy blast, renders it into dust and air. \n"
                    << "Victorious, Zen sets out for his escape pod, retreating to base before more aliens arrive. \n"
                    << "Thank for completing this short demo / visualizer for my game! \n"
                    << ">>>       **RIP THE PAGE!**       <<< \n";
               return 0;

          } else if (!zen.isAlive()) {
               string BruteWin1;
               string BruteWin2;
               string BruteWin3;
               cout << "Zen clutches his chest, panting from exhaustion. Despite this, he wills his mutation to his hand, to form a battl- \n"
                    << ">>> **CHHKKK**  <<< \n"
                    << "A sharp sword-like limb protrudes from Zen's chest, causing unbearable pain and damage. \n";
               cin  >> BruteWin1;
               cout << string(3, '\n');

               cout << "The Brute whispers, in a gravely, soft, but hideous tone, right in Zen's ear. \n"
                    << "\"Know your place.\" \n"
                    << "It takes out the limb with grace, leaving a gaping hole in Zen's chest. He instantly goes down to the ground. \n"
                    << "Input any key to.. i dont know.. die? \n";
               cin >> BruteWin2;
               cout << string(3, '\n');

               cout << "'well fuck, here we go again', he thinks to himself, and as his vision starts going in and out, \n"
                    << "He pours the last of his strength and ORIGIN into the USB Drive in his pocket, \n"
                    << "loading a \"failsafe, save state\" from earlier. \n"
                    << "Input any key to reset time and try again \n";
               cin >> BruteWin3;
               cout << string(3, '\n');

               cout << "Time starts to slow and bit by bit to a stop. The birds stop chirping, the land comes silent. \n"
                    <<  "Suddenly, every starts reversing, like a film going backwards. Up until the very moment that Zen walks back from the shelter.. \n"
                    <<  ">>>    **GAME OVER**    <<< \n"
                    <<  ">>>  **RESTART THE PROGRAM **   <<<\n";
               return 0;
          }
     }
}

