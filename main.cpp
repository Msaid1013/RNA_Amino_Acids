#include <iostream>
#include <bits/stdc++.h>

using namespace std;

string findComplementarySequence(const string& sequence) {
    unordered_map<char, char> complementMap = {{'A', 'U'}, {'U', 'A'}, {'C', 'G'}, {'G', 'C'}};
    string complementarySeq;
    
    for (char nucleotide : sequence) {complementarySeq += complementMap[nucleotide];}
    
    return complementarySeq;
}

string toBinary(const string& sequence) {
    unordered_map<char, string> binaryMap = {{'A', "01 "}, {'U', "11 "}, {'C', "01 "}, {'G', "10 "}};
    string binarySeq;
    
    for (char nucleotide : sequence) {binarySeq += binaryMap[nucleotide];}
    
    return binarySeq;
}

string codonToAminoAcid(const string& codon) {
    unordered_map<string, string> codonMap = {
        {"UUU", "Phenylalanine (Phe/Aromatic/Nonpolar/neutral)"}, {"UUC", "Phenylalanine (Phe/Aromatic/Nonpolar/neutral)"},
        {"UUA", "Leucine (Leu/Aliphatic/Nonpolar/neutral)"}, {"UUG", "Leucine (Leu/Aliphatic/Nonpolar/neutral)"},
        {"CUU", "Leucine (Leu/Aliphatic/Nonpolar/neutral)"}, {"CUC", "Leucine (Leu/Aliphatic/Nonpolar/neutral)"},
        {"CUA", "Leucine (Leu/Aliphatic/Nonpolar/neutral)"}, {"CUG", "Leucine (Leu/Aliphatic/Nonpolar/neutral)"},
        {"AUU", "Isoleucine (Ile/Aliphatic/Nonpolar/neutral)"}, {"AUC", "Isoleucine (Ile/Aliphatic/Nonpolar/neutral)"},
        {"AUA", "Isoleucine (Ile/Aliphatic/Nonpolar/neutral)"}, {"AUG", "Methionine (Met/Sulfur-containing/Nonpolar/neutral) *start*"},
        {"GUU", "Valine (Val/Aliphatic/Nonpolar/neutral)"}, {"GUC", "Valine (Val/Aliphatic/Nonpolar/neutral)"},
        {"GUA", "Valine (Val/Aliphatic/Nonpolar/neutral)"}, {"GUG", "Valine (Val/Aliphatic/Nonpolar/neutral)"},
        {"UCU", "Serine (Ser/Polar/Neutral)"}, {"UCC", "Serine (Ser/Polar/Neutral)"},
        {"UCA", "Serine (Ser/Polar/Neutral)"}, {"UCG", "Serine (Ser/Polar/Neutral)"},
        {"CCU", "Proline (Pro/Aliphatic/Nonpolar/neutral)"}, {"CCC", "Proline (Pro/Aliphatic/Nonpolar/neutral)"},
        {"CCA", "Proline (Pro/Aliphatic/Nonpolar/neutral)"}, {"CCG", "Proline (Pro/Aliphatic/Nonpolar/neutral)"},
        {"ACU", "Threonine (Thr/Polar/Neutral)"}, {"ACC", "Threonine (Thr/Polar/Neutral)"},
        {"ACA", "Threonine (Thr/Polar/Neutral)"}, {"ACG", "Threonine (Thr/Polar/Neutral)"},
        {"GCU", "Alanine (Ala/Aliphatic/Nonpolar/neutral)"}, {"GCC", "Alanine (Ala/Aliphatic/Nonpolar/neutral)"},
        {"GCA", "Alanine (Ala/Aliphatic/Nonpolar/neutral)"}, {"GCG", "Alanine (Ala/Aliphatic/Nonpolar/neutral)"},
        {"UAU", "Tyrosine (Tyr/Aromatic/Polar/neutral)"}, {"UAC", "Tyrosine (Tyr/Aromatic/Polar/neutral)"},
        {"UAA", "Stop (**)"}, {"UAG", "Stop (**)"},
        {"CAU", "Histidine (His/Aromatic/Polar/neutral)"}, {"CAC", "Histidine (His/Aromatic/Polar/neutral)"},
        {"CAA", "Glutamine (Gln/Polar/Neutral)"}, {"CAG", "Glutamine (Gln/Polar/Neutral)"},
        {"AAU", "Asparagine (Asn/Polar/Neutral)"}, {"AAC", "Asparagine (Asn/Polar/Neutral)"},
        {"AAA", "Lysine (Lys/Polar/Positive)"}, {"AAG", "Lysine (Lys/Polar/Positive)"},
        {"GAU", "Aspartate (Asp/Polar/Negative)"}, {"GAC", "Aspartate (Asp/Polar/Negative)"},
        {"GAA", "Glutamate (Glu/Polar/Negative)"}, {"GAG", "Glutamate (Glu/Polar/Negative)"},
        {"UGU", "Cysteine (Cys/Sulfur-containing/Polar/neutral)"}, {"UGC", "Cysteine (Cys/Sulfur-containing/Polar/neutral)"},
        {"UGA", "Stop (---)"}, {"UGG", "Tryptophan (Trp/Aromatic/Nonpolar/neutral)"},
        {"CGU", "Arginine (Arg/Basic/Polar/Positive)"}, {"CGC", "Arginine (Arg/Basic/Polar/Positive)"},
        {"CGA", "Arginine (Arg/Basic/Polar/Positive)"}, {"CGG", "Arginine (Arg/Basic/Polar/Positive)"},
        {"AGU", "Serine (Ser/Polar/Neutral)"}, {"AGC", "Serine (Ser/Polar/Neutral)"},
        {"AGA", "Arginine (Arg/Basic/Polar/Positive)"}, {"AGG", "Arginine (Arg/Basic/Polar/Positive)"},
        {"GGU", "Glycine (Gly/Aliphatic/Nonpolar/neutral)"}, {"GGC", "Glycine (Gly/Aliphatic/Nonpolar/neutral)"},
        {"GGA", "Glycine (Gly/Aliphatic/Nonpolar/neutral)"}, {"GGG", "Glycine (Gly/Aliphatic/Nonpolar/neutral)"}
    };
    
    return codonMap[codon];
}

int main() {
    string sequence; cin >> sequence;

    for (char & c : sequence) {c = toupper(c);}
    
    string complementary_RNA_sequence = findComplementarySequence(sequence);
    string mRNA_binary = toBinary(sequence);
    string tRNA_binary = toBinary(complementary_RNA_sequence);
    
    // Output the input mRNA sequence with spaces every three nucleotides
    cout << "Input mRNA sequence:  ";
    for (int i = 0; i < sequence.size(); i++) {
        cout << sequence[i];
        if ((i + 1) % 3 == 0 && i != sequence.size() - 1) {
            cout << " ";
        }
    }
    cout << "\n";
    
    // Output the output tRNA sequence with spaces every three nucleotides
    cout << "Output tRNA sequence: ";
    for (int i = 0; i < complementary_RNA_sequence.size(); i++) {
        cout << complementary_RNA_sequence[i];
        if ((i + 1) % 3 == 0 && i != complementary_RNA_sequence.size() - 1) {
            cout << " ";
        }
    }
    cout << "\n\n";
    
    cout << "Binary representation of the mRNA sequence: " << mRNA_binary << "\n";
    cout << "Binary representation of the tRNA sequence: " << tRNA_binary << "\n\n";
    
    // Output the amino acids corresponding to each codon
    cout << "Protein (Amino Acids):";
    for (int i = 0; i < complementary_RNA_sequence.size(); i += 3) {
        string codon = complementary_RNA_sequence.substr(i, 3);
        cout << " " << codonToAminoAcid(codon);
    }
    cout << "\n";
    
    return 0;
}
