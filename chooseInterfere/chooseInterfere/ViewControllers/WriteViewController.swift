//
//  WriteViewController.swift
//  chooseInterfere
//
//  Created by 최강훈 on 2021/07/14.
//

import UIKit
import Firebase
import FirebaseDatabase

class WriteViewController: UIViewController {

    @IBOutlet weak var userIdTextField: UITextField!
    @IBOutlet weak var userNickNameTextField: UITextField!
    @IBOutlet weak var titleTextField: UITextField!
    @IBOutlet weak var descriptionTextView: UITextView!
    @IBOutlet weak var optionListTableView: UITableView!
    @IBOutlet weak var optionInputTextField: UITextField!
    
    var options: [VoteOption] = []
    
    override func viewDidLoad() {
        super.viewDidLoad()

        self.optionListTableView.delegate = self
        self.optionListTableView.dataSource = self
        
        
        
    }
    
    @IBAction func touchUpAddOptionButton(_ sender: Any) {
        
        guard let optionText = self.optionInputTextField.text
        else { return }
        
        let voteOption = VoteOption(option: optionText, optionCount: 0)
        self.options.append(voteOption)
        self.optionInputTextField.text = ""
        
        DispatchQueue.main.async {
            self.optionListTableView.reloadData()
        }
        
    }
    
    @IBAction func touchUpSubmitButton(_ sender: Any) {
        
        guard let userId = userIdTextField.text,
            let userNickName = userNickNameTextField.text,
            let title = titleTextField.text,
            let description = descriptionTextView.text
        else {
            print("요건 불 충족 에러처리해야.")
            return
        }
        
        if self.options.count < 2 { return }
        
        var post = Post.init(createDate: Date(),
                             modifyDate: Date(),
                             title: title,
                             description: description,
                             images: nil,
                             isLike: false,
                             userNickName: userNickName,
                             viewCount: 1,
                             commentCount: 0,
                             comments: nil,
                             voteOptions: nil,
                             likeCount: 0)
        
        
        
        
        var ref: DatabaseReference!
        ref = Database.database().reference()
        ref.child("posts").setValue(
            ["userId": userId,
             "userNickName": userNickName,
             "title": title,
             "description": description,
             "createDate": nil,
             "modifyDate": nil,
             "images": nil,
             "isLike": false,
             "likeCount": 0,
             "viewCount": 0,
             "commentCount": 0,
             "comments": nil
             
        ])
        
        
        
        
        
        
    }
    
}


extension WriteViewController: UITableViewDelegate, UITableViewDataSource {
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        self.options.count
    }
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        guard let cell = self.optionListTableView.dequeueReusableCell(withIdentifier: OptionListTableViewCell.reuseIdentifier, for: indexPath)
        as? OptionListTableViewCell
        else { return UITableViewCell() }
        
        cell.optionLabel?.text = self.options[indexPath.row].option
        
        
        
        return cell
    }
    
    
}
