//
//  HomeContentsTableViewCell.swift
//  chooseInterfere
//
//  Created by 최강훈 on 2021/07/13.
//

import UIKit

class HomeContentsTableViewCell: UITableViewCell {

    static let staticReuseIdentifier: String = "homeContetnsTableVieWCell"
    
    @IBOutlet weak var titleLabel: UILabel!
    @IBOutlet weak var userNickNameDateViewCountLabel: UILabel!
    @IBOutlet weak var descriptionLabel: UILabel!
    @IBOutlet weak var thumbnailImageView: UIImageView!
    @IBOutlet weak var imageCountLabel: UILabel!
    @IBOutlet weak var imageContainerView: UIView!
    @IBOutlet weak var isLikeImageView: UIImageView!
    @IBOutlet weak var likeCountLabel: UILabel!
    @IBOutlet weak var commentCountLabel: UILabel!
    
    override func awakeFromNib() {
        super.awakeFromNib()
        // Initialization code
    }

    override func setSelected(_ selected: Bool, animated: Bool) {
        super.setSelected(selected, animated: animated)

        // Configure the view for the selected state
    }

}
