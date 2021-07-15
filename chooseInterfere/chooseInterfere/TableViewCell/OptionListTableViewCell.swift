//
//  OptionListTableViewCell.swift
//  chooseInterfere
//
//  Created by 최강훈 on 2021/07/14.
//

import UIKit

class OptionListTableViewCell: UITableViewCell {

    static let reuseIdentifier = "optionTableViewCell"
    
    @IBOutlet weak var optionLabel: UILabel!
    
    override func awakeFromNib() {
        super.awakeFromNib()
        // Initialization code
    }

    override func setSelected(_ selected: Bool, animated: Bool) {
        super.setSelected(selected, animated: animated)

        // Configure the view for the selected state
    }

}
